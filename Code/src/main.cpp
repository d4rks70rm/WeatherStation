#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <ArduinoOTA.h>
#include "variable.h"
#include "bmp180.h"
#include "dht22.h"
#include "lib_wifi.h"
#include "mqtt.h"

bool OTAStarted = false;

void onOTAStart() {
  OTAStarted = true;
}

void onOTAEnd() {
    OTAStarted = false;
}


void setup() {
  pinMode(D0, WAKEUP_PULLUP);
  
  Serial.begin(115200);
  dht.begin();
  if (pressure.begin())
    Serial.println("BMP180 init success");
  else
  {
    delay(5000);
    Serial.println("BMP180 init fail (disconnected?)\n\n");
  }

  connectWifi(); 

  ArduinoOTA.setHostname((const char *)clientName.c_str());
  ArduinoOTA.begin();
  ArduinoOTA.onStart(onOTAStart);
  ArduinoOTA.onEnd(onOTAEnd);


  if (checkMqttConnection()){   
    Serial.println("connected: ");
    delay(1000); 
  }

}

void loop() {
  ArduinoOTA.handle();
  if (OTAStarted) {
    return;
  }

  if (WiFi.status() == WL_CONNECTED) {
    while(checkMqttConnection()){  
      client.loop();
      String temperature = String(readTemperature());
      String humidity = String(readHumidity());
      String pressure = String(getPressure());
      String bat = String(analogRead(A0)/209.66);

      sendToMQTT(temperature,TempTopic);
      sendToMQTT(humidity,HumTopic);
      sendToMQTT(pressure,PressureTopic);
      sendToMQTT(bat,BatTopic);

      ESP.deepSleep(durationSleep);
      delay(1000);
    }
  }else{
    connectWifi();
  }
}
#ifndef LIBWIFI_H
#define LIBWIFI_H
#include <ESP8266WiFi.h> 

//Wifi Info


WiFiClient wifi_client;

void connectWifi(){
  WiFi.begin(ssid, password);
  
  
  //WiFi.mode(WIFI_STA);
  Serial.println(".");


  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Ligado a ");
  Serial.println(ssid);
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP()); 
}

#endif
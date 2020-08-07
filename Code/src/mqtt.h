#ifndef MQTT_H
#define MQTT_H
#include <PubSubClient.h>


//CallBack MQTT
void callback(char* topic, byte* payload, unsigned int length) {
  int i = 0;

  Serial.println("Message arrived:  topic: " + String(topic));
  Serial.println("Length: " + String(length,DEC));
  
  for(i=0; i<length; i++) {
    message_buff[i] = payload[i];
  }  message_buff[i] = '\0';
  
  String msgString = String(message_buff);
  
  Serial.println("Payload: " + msgString);
  Serial.println(msgString);

}

PubSubClient client(server, 1883, callback,  wifi_client);

bool checkMqttConnection(){
  if (!client.connected()) {
    if (client.connect(clientName.c_str(),MQTT_USERNAME, MQTT_PASSWORD) ) {
      Serial.println("CONNECTED");
    }
  }
  return client.connected();
}

void sendToMQTT(String value,char* topic){
    char payload[value.length()+1];
    value.toCharArray(payload,value.length()+1);
    client.publish( topic, payload, true);
    delay(1000); 
    Serial.println(topic);
    Serial.println(payload);
}

#endif
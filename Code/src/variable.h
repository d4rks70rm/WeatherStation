#ifndef VARIABLE_H
#define VARIABLE_H
//----------------DHT22 Section --------------------
#define DHTPIN D3
#define DHTTYPE DHT22
//--------------------------------------------------
//----------------MQTT Section ---------------------
#define MQTT_AUTH true
#define MQTT_USERNAME "MQTT_USER"
#define MQTT_PASSWORD "MQTT_PASSWORD"
char* TempTopic = "TEMPERATURE_TOPIC";
char* HumTopic = "HUMIDITY_TOPIC";
char* PressureTopic = "PRESSURE_TOPIC";
char* BatTopic = "BAT_TOPIC";
const char* server = "SERVER";
String clientName = "NODE-NAME";
char message_buff[100]; 
//--------------------------------------------------
//----------------Deep Sleep Section ---------------
#define durationSleep  36e8
//--------------------------------------------------
//----------------WIFI Section ---------------------
char* ssid     = "SSID";
const char* password = "PASSWORD";
//--------------------------------------------------
#endif
#ifndef DHT22_H
#define DHT22_H
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

DHT dht(DHTPIN, DHTTYPE);

float readTemperature(){
  return dht.readTemperature();
}

float readHumidity(){
  return dht.readHumidity();
}

#endif
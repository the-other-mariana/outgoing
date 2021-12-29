// code that prints temperature on serial monitor
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT11 output:");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp = dht.readTemperature();
  if (isnan(temp)) {
    Serial.println("No data");
  }else{
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println("°C");
    delay(1000);
  }
  
}

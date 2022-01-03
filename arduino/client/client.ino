// code that prints temperature on serial monitor
#include <WiFi.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "INFINITUM_C8647A"; // network name
const char* password = "F26DC8647B";
const char* host = "127.0.0.1";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("DHT11 output:");
  dht.begin();

  // connect to wifi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("[SUCCESS] Wifi connected");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
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
    delay(3000);
  }

  Serial.print("Connecting to ");
  Serial.println(host);

  // WiFiClient class creates TCP connections
  WiFiClient client;
  const int httpPort = 8080;
  if (!client.connect(host, httpPort)){
    Serial.println("[FAIL] Client connection failed");
    return;
  }

  // send request to server
  client.print(String("GET http://127.0.0.1:8080/dht?temp=") + temp); 
  unsigned long timeout = millis();
  while(client.available() == 0) {
    if (millis() - timeout > 1000){
      Serial.println("[ERROR] Client timeout");
      client.stop();
      return;
    }
  }

  // read server reply and print in to serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("Closing connection");
  
}

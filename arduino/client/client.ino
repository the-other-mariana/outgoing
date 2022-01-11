// code that prints temperature on serial monitor
#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "INFINITUM_C8647A"; // network name
const char* password = "F26DC8647B";
const char* host = "192.168.1.75";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("DHT11 output:");
  dht.begin();

  // connect to wifi network
  Serial.println();
  Serial.println();
  Serial.print("[WIFI] Connecting to ");
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

  if (WiFi.status() == WL_CONNECTED){
    HTTPClient http;
    int httpPort = 8080;

    http.begin(String("http://") +  host + String(":") + String(httpPort) + String("/dht?temp=") + String(temp));
    int httpCode = http.GET();

    if (httpCode > 0){
      String payload = http.getString();
      Serial.println(httpCode);
      Serial.println(payload);
    } else {
      Serial.println("[ERROR] HTTP request code < 0");
    }
    http.end();
  }
  delay(10000);
}

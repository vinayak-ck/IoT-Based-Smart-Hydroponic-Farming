/*************************************************************
  Urban Smart Farming Box using ESP32 and Blynk
*************************************************************/

#define BLYNK_PRINT Serial  // Enable debug output to Serial

#define BLYNK_TEMPLATE_ID "TMPL3_iLYYE5p"
#define BLYNK_TEMPLATE_NAME "Urban Smart Farming Box"
#define BLYNK_AUTH_TOKEN "R722PPHuyVU8YkSO3eEoE7V8ygYt84uY"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"  // Include DHT library

// WiFi credentials
char ssid[] = "BEAST👻";
char pass[] = "mohan123";

// Blynk auth
char auth[] = BLYNK_AUTH_TOKEN;

// DHT11 configuration
#define DHTPIN 27
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Sensor & relay pins
#define LDR_PIN 32
#define WATER_LEVEL_PIN 33
#define RELAY_PIN 25

int pumpToggle = 0;

// Handle pump ON/OFF from Blynk switch (V4)
BLYNK_WRITE(V4) {
  pumpToggle = param.asInt();
  digitalWrite(RELAY_PIN, pumpToggle);
}

void setup() {
  Serial.begin(115200);

  pinMode(LDR_PIN, INPUT);
  pinMode(WATER_LEVEL_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);  // Make sure relay is OFF at start

  dht.begin();
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();

  // Read sensor values
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // Check for failed readings
  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  int ldrStatus = digitalRead(LDR_PIN);             // 0 = Dark, 1 = Bright
  int waterLevelStatus = digitalRead(WATER_LEVEL_PIN); // 0 = Low, 1 = Sufficient

  // Send values to Blynk app
  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, hum);
  Blynk.virtualWrite(V2, ldrStatus);
  Blynk.virtualWrite(V3, waterLevelStatus);

  // Debugging output
  Serial.print("Temp: "); Serial.print(temp); Serial.print("°C, ");
  Serial.print("Humidity: "); Serial.print(hum); Serial.print("%, ");
  Serial.print("Light: "); Serial.print(ldrStatus ? "Bright" : "Dark"); Serial.print(", ");
  Serial.print("Water: "); Serial.println(waterLevelStatus ? "OK" : "Low");

  delay(2000);  // Update every 2 seconds
}

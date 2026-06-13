  #include <ESP8266WiFi.h> 
#include <PubSubClient.h> 
#include "DHT.h" 
 
// ================= PIN ================= 
#define LED_PIN     D5 
#define BUZZER_PIN  D6 
#define DHTPIN      D2 
#define DHTTYPE     DHT11 
#define RAIN_PIN    A0 
 
// ================= OBJECT ================= 
DHT dht(DHTPIN, DHTTYPE); 
WiFiClient espClient; 
PubSubClient client(espClient); 
 
// ================= WIFI & TB ================= 
const char* ssid = "iPhone Amai"; 
CODE ARDUINO 
const char* password = "mauyaaaaaa"; 
 
const char* mqttServer = "eu.thingsboard.cloud"; 
const int mqttPort = 1883; 
const char* token = "qc6pBavUV4hPlHSlqoo9"; 
 
// ================= SETUP ================= 
void setup() { 
  Serial.begin(9600); 
 
  pinMode(LED_PIN, OUTPUT); 
  pinMode(BUZZER_PIN, OUTPUT); 
  digitalWrite(LED_PIN, LOW); 
  digitalWrite(BUZZER_PIN, LOW); 
 
  dht.begin(); 
 
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500); 
    Serial.print("."); 
  } 
  Serial.println("\nWiFi Connected"); 
 
  client.setServer(mqttServer, mqttPort); 
} 
 
// ================= MQTT CONNECT ================= 
void reconnect() { 
  while (!client.connected()) { 
    Serial.print("Connecting to ThingsBoard..."); 
    if (client.connect("RainSenseClient", token, NULL)) { 
      Serial.println("Connected"); 
    } else { 
      Serial.print("Failed rc="); 
      Serial.println(client.state()); 
      delay(2000); 
    } 
  } 
} 
 
// ================= LOOP ================= 
void loop() { 
  if (!client.connected()) { 
    reconnect(); 
  } 
  client.loop(); 
 
  float temperature = dht.readTemperature(); 
  float humidity = dht.readHumidity(); 
 
  int rainValue = analogRead(RAIN_PIN); 
  int rainStatus = (rainValue < 500) ? 1 : 0; 
 
  // ===== AKTUATOR ===== 
  if (rainStatus == 1) { 
    digitalWrite(LED_PIN, HIGH); 
    digitalWrite(BUZZER_PIN, HIGH); 
  } else { 
    digitalWrite(LED_PIN, LOW); 
    digitalWrite(BUZZER_PIN, LOW); 
  } 
 
  // ===== PAYLOAD ===== 
  String payload = "{"; 
  payload += "\"temperature\":" + String(temperature) + ","; 
  payload += "\"humidity\":" + String(humidity) + ","; 
  payload += "\"rain\":" + String(rainStatus); 
  payload += "}"; 
 
  client.publish("v1/devices/me/telemetry", payload.c_str()); 
  Serial.println(payload); 
 
  delay(5000); 
} 
 
 
 

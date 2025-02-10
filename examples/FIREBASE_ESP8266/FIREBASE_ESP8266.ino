#include <FIREBASE_ESP8266.h> // Library for Firebase integration

#define WIFI_SSID "EXAMPLE" // WiFi SSID
#define WIFI_PASSWORD "EXAMPLE" // WiFi Password
#define FIREBASE_HOST "https://EXAMPLE-EXAMPLE-default-EXAMPLE.firebaseio.com" // Firebase Database URL
#define FIREBASE_PATH "/example.json" // Firebase Data Path

// Create an instance of FIREBASE_ESP8266 with WiFi credentials and Firebase database details
FIREBASE_ESP8266 FIREBASE_ESP8266(FIREBASE_HOST, FIREBASE_PATH, WIFI_SSID, WIFI_PASSWORD);

void setup() {
  Serial.begin(115200); // Initialize serial communication at 115200 baud rate
  FIREBASE_ESP8266.connectWiFi(); // Connect to WiFi using the provided credentials
}

void loop() {
  // Define keys (parameter name) for the data to be sent
  String keys[] = {"temperature", "humidity", "pressure"};
  // Define values (random for demo) corresponding to the keys
  int values[] = {random(0, 35), random(0, 100), random(900, 1100)};

  // Send data to Firebase using the custom library
  FIREBASE_ESP8266.sendData(keys, values, 3);

  // Wait for 1 second before sending the next data
  delay(1000);
}

#include "FIREBASE_ESP8266.h"

FIREBASE_ESP8266::FIREBASE_ESP8266(const String& HOST, const String& PATH, const String& SSID, const String& PASS) {
	_HOST = HOST;
	_PATH = PATH;
	_SSID = SSID;
	_PASS = PASS;
}

void FIREBASE_ESP8266::connectWiFi() {
	WiFi.begin(_SSID, _PASS);
	Serial.print("Connecting to WiFi");
	while (WiFi.status() != WL_CONNECTED) {
		Serial.println("Connecting");
		Serial.print(".");
		delay(500);
	}

	Serial.println("\nWiFi Connected !");
	Serial.println("IP Address : ");
	Serial.print(WiFi.localIP());
	_client.setInsecure();
}

void FIREBASE_ESP8266::sendData(const String keys[], const int values[], int dataCount) {
	if (WiFi.status() == WL_CONNECTED) {
		HTTPClient http;
		String URL = _HOST + _PATH;
		http.begin(_client, URL);
		http.addHeader("Content-Type", "application/json");

		StaticJsonDocument<200> jsonDoc;
		
		for (int i = 0; i < dataCount; i++) {
			jsonDoc[keys[i]] = values[i];
		}

		String jsonString;
		serializeJson(jsonDoc, jsonString);
		
		int httpResponseCode = http.PUT(jsonString);

		if (httpResponseCode > 0) {
			Serial.println(httpResponseCode);
		} else {
			Serial.println(http.errorToString(httpResponseCode).c_str());
		}
	}
}

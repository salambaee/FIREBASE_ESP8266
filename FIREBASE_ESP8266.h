#ifndef FIREBASE_ESP8266_H
#define FIREBASE_ESP8266_H

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

class FIREBASE_ESP8266 {
	public:
		FIREBASE_ESP8266(const String& HOST, const String& PATH, const String& SSID, const String& PASS);
		void connectWiFi();
		void sendData(const String keys[], const int values[], int dataCount);
	private:
		String _SSID;
		String _PASS;
		String _HOST;
		String _PATH;
		WiFiClientSecure _client;
};

#endif

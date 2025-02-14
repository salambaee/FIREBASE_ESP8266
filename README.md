# ESP8266 Firebase Library
This library allows an ESP8266 microcontroller to send sensor data to a Firebase Realtime Database.

## Features
1. Connects to a WiFi.
2. Sends sensor data
3. Uses HTTP for secure communication
4. Loops every second to update data

## Requirements
1. ESP8266-based board (e.g., NodeMCU, Wemos D1 Mini)
2. Arduino IDE with the following libraries installed :
   * ESP8266WiFi (included in the ESP8266 Core for Arduino, needs to be installed via Board Manager)
   * WiFiClientSecure (included in the ESP8266 Core for Arduino, needs to be installed via Board Manager)
   * ESP8266HTTPClient (included in the ESP8266 Core for Arduino, needs to be installed via Board Manager)
   * ArduinoJson ([included in this repository](https://docs.arduino.cc/libraries/arduinojson/))

## Installation
### Linux
1. Open the terminal and navigate to the libraries directory inside the Arduino folder :
   ```bash
   cd ~/Arduino/libraries/
2. Clone this repository or download the source files.
   ```bash
   git clone https://github.com/salambaee/FIREBASE_ESP8266.git
3. If downloaded manually, extract the ZIP folder into `~/Arduino/libraries/`
4. Restart the Arduino IDE to detect the library

### Windows
1. Open File Explorer and navigate to the libraries directory inside the Arduino folder (usually located in `Documents/Arduino/libraries`).
2. Download or clone the library into this folder :
   ```bash
   git clone https://github.com/salambaee/FIREBASE_ESP8266.git
3. If downloading a ZIP file, extract it to `Documents/Arduino/libraries/`
4. Restart the Arduino IDE to detect the library.

## Notes
Ensure your Firebase database rules allow writing data
```
{
  "rules": {
    ".read": "true",
    ".write": "true"
  }
}
```
The data sent in this example is randomly generated. Replace it with actual sensor readings if needed.

## Example
```C
#include <FIREBASE_ESP8266.h>
#define WIFI_SSID "EXAMPLE"
#define WIFI_PASSWORD "example"
#define FIREBASE_HOST "https://data-sensor-EXAMPLE-default-EXAMPLE.firebaseio.com/"
#define FIREBASE_PATH "/sensor.json"

FIREBASE_ESP8266 FIREBASE_ESP8266(FIREBASE_HOST, FIREBASE_PATH, WIFI_SSID, WIFI_PASSWORD);

void setup() {
  Serial.begin(115200);
  FIREBASE_ESP8266.connectWiFi();
}

void loop() {
  int Sensor_1 = random(1, 20);
  int Sensor_2 = random(2, 20);
  int Sensor_3 = random(3, 20);
  String keys[] = {"Sensor_1", "Sesnor_2", "Sensor_3"};
  int values[] = {Sensor_1, Sensor_2, Sensor_3}
  FIREBASE_ESP8266.sendData(keys, values, 1);
}
```
* `#include <FIREBASE_ESP8266>` This line attemps to include a installed library
* `#define WIFI_SSID "EXAMPLE"` and `#define WIFI_PASSWORD "example"` define the Wi_Fi network that the ESP8266 will connect to.
* `#define FIREBASE_HOST` is the URL of the Firebase Realtime Database.
* `#define FIREBASE_PATH` specifies the database path where data will be stored.
* `FIREBASE_ESP8266 FIREBASE_ESP8266(FIREBASE_HOST, FIREBASE_PATH, WIFI_SSID, WIFI_PASSWORD);` This attempts to create an instance of FIREBASE_ESP8266.
* `FIREBASE_ESP8266.connectWiFi();` attempts to connect the ESP8266 to the specified Wi-Fi.

## License
This project is open-source and available under the MIT License

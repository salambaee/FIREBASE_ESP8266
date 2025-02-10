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
   * ArduinoJson (included in this repository)

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

## License
This project is open-source and available under the MIT License

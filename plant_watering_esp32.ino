// Arduino code for ESP32-based Plant Watering System

#include <WiFi.h>
#include <WebServer.h>

// Configuration
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// Pump and sensor configuration
const int pumpPins[5] = {5, 18, 19, 21, 22}; // GPIO pins for 5 pumps
const int levelSensors[4] = {34, 35, 32, 33}; // GPIO pins for 4 level sensors
const int moistureSensors[5] = {36, 39, 34, 35, 32}; // GPIO pins for 5 moisture sensors

// Web server on port 80
WebServer server(80);

void setup() {
    // Initialize serial communication for debugging
    Serial.begin(115200);
    
    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
    
    // Initialize pumps and sensors
    for (int i = 0; i < 5; i++) {
        pinMode(pumpPins[i], OUTPUT);
        digitalWrite(pumpPins[i], LOW); // Ensure pumps are off
    }
    for (int i = 0; i < 4; i++) {
        pinMode(levelSensors[i], INPUT);
    }
    for (int i = 0; i < 5; i++) {
        pinMode(moistureSensors[i], INPUT);
    }
    
    // Define API endpoints
    server.on("/water", HTTP_GET, handleWater);
    server.on("/status", HTTP_GET, handleStatus);
    server.begin();
}

void loop() {
    server.handleClient(); // Handle incoming client requests
    automaticWatering(); // Check conditions for automatic watering
}

void handleWater() {
    String response = "Watering Started";
    for (int i = 0; i < 5; i++) {
        digitalWrite(pumpPins[i], HIGH); // Turn on pumps
        delay(1000); // Water for 1 second
        digitalWrite(pumpPins[i], LOW); // Turn off pumps
    }
    server.send(200, "text/plain", response);
}

void handleStatus() {
    String status = "System Status:\n";
    for (int i = 0; i < 5; i++) {
        int moisture = analogRead(moistureSensors[i]);
        status += "Moisture sensor " + String(i+1) + ": " + String(moisture) + "\n";
    }
    server.send(200, "text/plain", status);
}

void automaticWatering() {
    for (int i = 0; i < 5; i++) {
        int moisture = analogRead(moistureSensors[i]);
        // Example condition to start watering based on moisture level
        if (moisture < 400) {
            digitalWrite(pumpPins[i], HIGH); // Turn on pump
            delay(1000); // Water for 1 second
            digitalWrite(pumpPins[i], LOW); // Turn off pump
        }
    }
} 

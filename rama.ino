#include <DHT.h>  // Include DHT sensor library

#define DHTPIN 2   // Define the pin for DHT sensor
#define DHTTYPE DHT11  // Specify sensor type (DHT11)
#define VENTILATEURPIN 7  // Define pin for fan

DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT sensor

void setup() {
    Serial.begin(9600);  
    dht.begin();  
    pinMode(VENTILATEURPIN, OUTPUT);  // Fix function name
}

void loop() {
    float temp = dht.readTemperature();  // Read temperature
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println(" °C");

    // Fan control logic
    if (temp > 16) {  
        analogWrite(VENTILATEURPIN, 255);  // Turn fan on
    } else {  
        analogWrite(VENTILATEURPIN, 0);  // Turn fan off
    }

    delay(1000);  // Wait 1 second before next reading
}

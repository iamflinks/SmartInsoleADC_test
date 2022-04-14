#include <Arduino.h>

const int adcPIN = 34;
uint16_t binary = 0;
unsigned long loopInterval = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Resistance measurement");
  delay(500);
}

void loop() {
  binary = analogRead(adcPIN);
  if (millis() - loopInterval >= 1000)
  {
    loopInterval += 1000;
    // Convert to resistance
    float voltage = binary * 3.3 / 4096;
    float resistance = (4700 * (binary * 3.3 / 4096)) / (3.3 - (binary * 3.3 / 4096));
    Serial.print("Voltage:  ");Serial.print(voltage);Serial.print('\n');
    Serial.print("Raw:  ");Serial.print(binary);Serial.print('\n');
    Serial.print("Resistance :  ");Serial.print(voltage);Serial.print('\n');
  }
  
}
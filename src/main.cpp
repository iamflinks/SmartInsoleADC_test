#include <Arduino.h>

#define adcPIN 34
uint16_t binary = 0;
unsigned long loopInterval = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Resistance measurement");
}

void loop() {
  binary = analogRead(adcPIN);
  if (millis() - loopInterval >= 1000)
  {
    // Convert to resistance
    float resistance = (4700 * (binary * 3.3 / 4096)) / (3.3 - (binary * 3.3 / 4096));
    Serial.print("Resistance:  ");Serial.print(resistance);Serial.print('\n');
  }
  
}
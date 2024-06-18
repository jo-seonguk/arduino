#include <SoftwareSerial.h>
#define rxPin 3
#define txPin 2
SoftwareSerial esp01(txPin, rxPin);

void setup() {
  Serial.begin(115200);
  esp01.begin(115200);
}

void loop() {
  if (esp01.available()) {
    Serial.write(esp01.read());
  }
  if (Serial.available()) {
    esp01.write(Serial.read());
  }
}
 
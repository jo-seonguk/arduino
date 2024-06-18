#include <Servo.h>
Servo servo;

int pos = 0;
int servoPin = 6;

void setup() {
  pinMode (servoPin, OUTPUT);
  servo.attach(6);

}

void loop() {
  for(pos = 0; pos <= 180; pos += 1) {
    servo.write(pos); 
    delay(100);
  }
  for(pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);
    delay(100);
  } 
}
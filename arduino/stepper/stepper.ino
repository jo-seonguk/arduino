#include <Stepper.h>
const int steps = 2048;
Stepper stepper(steps, 11, 9, 10, 8);
void setup() {
  stepper.setSpeed(15);
  Serial.begin(9600);
}

void loop() {
  Serial.print("시계방향");
  stepper.step(steps);
  delay(500);
  Serial.println("반시계방향");
  stepper.step(-steps);
  delay(500);
}

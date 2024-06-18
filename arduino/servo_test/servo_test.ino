#include <Servo.h>

Servo servoMotor; // Servo 객체 생성

void setup() {
  servoMotor.attach(9); // 9번 핀에 서보모터 연결
}

void loop() {
  servoMotor.write(0); // 0도로 회전
  delay(1500); // 1초 대기

  servoMotor.write(90); // 90도로 회전
  delay(1500); // 1초 대기

  servoMotor.write(180); // 180도로 회전
  delay(1500); // 1초 대기
}
#define TRIG 9
#define ECHO 8
int led_R = 10;
int led_G = 11; 
int led_B = 12;
int buzzer = 5;

int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};  

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(led_R, OUTPUT);
  pinMode(led_G, OUTPUT);
  pinMode(led_B, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH); 

  distance = duration * 17 / 1000;    //초음파 거리 계산  원래는 340 * duration / 10000 / 2 이나 간단하게 줄임 
  Serial.println(duration);
  Serial.print("\nDistance : ");
  Serial.print(distance);
  Serial.print(" Cm");
  delay(1000);

  if(distance <= 10) {            // 물체(사람)과의 거리가 10cm인 경우 빨간 불 점등 및 부저가 melody 배열의 음에 맞춰 울림
    digitalWrite(led_R, HIGH);
    digitalWrite(led_G, LOW);
    digitalWrite(led_B, LOW);
    for(int i = 0; i<8; i++) {
      tone(buzzer, melody[i], 400);
      delay(500);
    }
  } else if(distance <= 20 & distance > 10) {   // 거리가 10~20 사이인 경우 초록 불 점등
    digitalWrite(led_R, LOW);
    digitalWrite(led_G, HIGH);
    digitalWrite(led_B, LOW);
    noTone(5);
  } else {                    // 20cm 이상인 경우 파란 불 점등
    digitalWrite(led_R, LOW);
    digitalWrite(led_G, LOW);
    digitalWrite(led_B, HIGH);
    noTone(5);
    
  }

}

int led_p[7] = {4, 5, 6, 7, 8, 9, 10};  //led 7개 핀


void setup() {
  int i = 0;
  for(i=0; i<7; i++) {              
    pinMode(led_p[i], OUTPUT);
  }

}


void loop() {
  int i = 0;
  for(i=0; i<7; i++) {      //led 순서대로 켜졌다 꺼졌다 반복
    digitalWrite(led_p[i], HIGH);
    delay(500);
    digitalWrite(led_p[i], LOW);
    delay(500);
    if (i > 7) {
      i = 0;
    }
  }
}

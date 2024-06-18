int buzzer = 5;
int sw = 4;

int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};


void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(sw)==0) {
    for(int a =0; a<8; a++) {
      tone(buzzer, melody[a], 400);
      delay(500);
    }
  }
  else {
    noTone(5);
  }
}

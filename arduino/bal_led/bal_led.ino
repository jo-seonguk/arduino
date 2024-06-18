int led = 6;  //led 
int ball = 7; //볼 스위치

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(ball, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(ball)) {
    digitalWrite(led, LOW);
  }
  else {
    digitalWrite(led, HIGH);
  }
}

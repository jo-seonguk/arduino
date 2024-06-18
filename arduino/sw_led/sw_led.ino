//int led1 = 5;
int led2 = 6;
int led3 = 7;
int sw = 8;

void setup() {
  pinMode(sw, INPUT);
  //pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  if(digitalRead(sw) == 0) {
    //digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  else {
    //digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  delay(100);
}

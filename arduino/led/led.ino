int led0 = 4;
int led1 = 5;
int led2 = 6;
int led3 = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(led0,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led0,HIGH);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  delay(1000);
  digitalWrite(led0,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  delay(1000);
}

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
  Serial.begin(9600);
  Serial.println("시리얼 통신 시작");
}


void loop() {
  if(Serial.available()){
    char a;
    a = Serial.read();
    if(a =='1'){
      digitalWrite(led0,HIGH);
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      Serial.println("LED ON");
    }
    if(a == '0'){
      digitalWrite(led0,LOW);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      Serial.println("LED OFF");
    }
  }
}

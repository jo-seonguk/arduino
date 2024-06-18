int led1 = 3; //오른      
int led2 = 4; //아래 
int led3 = 5; //위
int led4 = 6; //왼
int sw = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  Serial.print(analogRead(A0));
  // put your main code here, to run repeatedly:
  if(analogRead(A0) > 525 ) { // 오른쪽으로 가면 오른쪽 불이 켜짐
    digitalWrite(led3, HIGH); 
    digitalWrite(led2, LOW);
  } else if(analogRead(A0) < 500) { // 왼쪽으로 가면 왼쪽 불이 켜짐
    digitalWrite(led3, LOW);
    digitalWrite(led2, HIGH);
  } else {                                            //원위치시 불 꺼짐
    digitalWrite(led3, LOW);
    digitalWrite(led2, LOW);
  }

  if(analogRead(A1) > 525 ) { // 앞으로 가면 앞쪽 불이 켜짐
    digitalWrite(led1, HIGH);
    digitalWrite(led4, LOW);
  } else if(analogRead(A1) < 500) { // 뒤로 가면 뒤쪽 불이 켜짐
    digitalWrite(led1, LOW);
    digitalWrite(led4, HIGH);
  } else {                        //원위치시 불 꺼짐
    digitalWrite(led1, LOW);
    digitalWrite(led4, LOW);
  }
}


//만지지 않았을 때 고정된 값 x 513 y 506     조작 시 0~1023 사이 값 나옴 
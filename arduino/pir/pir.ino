int LED = 2;                                     // LED 출력 2번핀
int relay = 3;
int sensor = 7;                                 // 센서 입력값 7번핀
int value = 0;                                   // loop에서 사용할 value 변수 설정

void setup() {
    pinMode (LED, OUTPUT);          // 핀모드 LED 출력으로 설정
    pinMode (sensor, INPUT);          //  핀모드 센서 입력값으로 설정
    pinMode(relay, OUTPUT);
}

void loop() {
    value = digitalRead(sensor);        // 변수 value에 디지털 센서값 저장
    if(value == HIGH) {                        // value가 high라면
      //digitalWrite(relay, HIGH);
      digitalWrite(LED, HIGH);            // LED를 켜라
    } else {         
      //digitalWrite(relay, LOW);                                     // 그렇지 않다면
      digitalWrite(LED, LOW);             //  LED를 꺼라
    }
}
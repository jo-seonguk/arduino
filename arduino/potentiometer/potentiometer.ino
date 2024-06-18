#define max_R 10000   //가변저항 최대치

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial Com start");
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(A0);             //가변저항 값 읽어옴
  int resistor = map(val, 0, 1023, 0, max_R); 
  Serial.print("Resistor value.");
  Serial.print(resistor);
  Serial.println("ohm");
  delay(200);
}

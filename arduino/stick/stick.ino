int sw = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sw, INPUT_PULLUP);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("X축: ");
  Serial.print(analogRead(A0));
  Serial.print("\t");
  Serial.print("Y축: ");
  Serial.print(analogRead(A1));
  Serial.print("\t");
  Serial.print("스위치: ");
  Serial.println(digitalRead(sw));
  delay(100);
}

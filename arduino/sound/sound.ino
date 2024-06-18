int led = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
} 

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A2);

  int adjust = map(value, 0, 1024, 0, 255);
  analogWrite(led, adjust);
  Serial.println(value);
  delay(100);
}

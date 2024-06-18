#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int led_R = 9;
int led_G = 10; 
int led_B = 11;
int sw = 7;
void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(sw, INPUT_PULLUP);
  pinMode(led_R, OUTPUT);
  pinMode(led_G, OUTPUT);
  pinMode(led_B, OUTPUT);
}

void loop() {
  char str = 'X : ' + analogRead(A0) + ', Y : ' + analogRead(A1);
  
  if(analogRead(A0) > 525 ) { //스틱이 위로가면 
    digitalWrite(led_B, HIGH);
    digitalWrite(led_R, LOW);
  } else if(analogRead(A0) < 500) {
    digitalWrite(led_B, LOW);
    digitalWrite(led_R, HIGH);
  } else {
    digitalWrite(led_B, LOW);
    digitalWrite(led_R, LOW);
  }

  if(analogRead(A1) > 525 ) { //스틱이 위로가면 
    digitalWrite(led_G, HIGH);
  } else if(analogRead(A1) < 500) {
    digitalWrite(led_G, HIGH);
  } else {
    digitalWrite(led_G, LOW);
  }
}

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  Serial.println("LCD 통신 시작");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    delay(10);
    lcd.clear();
    while (Serial.available() > 0) {
      char val = Serial.read();
      
      if(val > 16) {
        Serial.print(val);
        lcd.print(val);
      } else {
        Serial.print("16자 이내로 입력해주세요");
        lcd.print("plz 16char below");
      }
    }
  }
}

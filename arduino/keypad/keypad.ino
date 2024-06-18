#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Key.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4;
const byte COLS = 4;
char myKeys[ROWS][COLS]= {  //키 패드 위치 배열
  {'1', '2', '3', '-'},
  {'4', '5', '6', '+'},
  {'7', '8', '9', 'x'},
  {'AC', '0', '=', '/'}
};

long a;     // 첫번째 입력 받는 값 
long b;     // 두번째 입력 받는 값
boolean op = false; // 연산자 입력됐는지 확인
char oper;          // 연산자 종류 
int sum;            // 결과 값

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {8, 9, 10, 11};

Keypad customKeypad = Keypad(makeKeymap(myKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  char customKey = customKeypad.getKey();   //키 패드 버튼이 눌린 값 받는 변수
  switch(customKey) {
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
      lcd.clear();
      lcd.setCursor(0,0);
      if(op) {
        b = b * 10 + (customKey - '0');
        lcd.print(a);
        lcd.print(oper);
        lcd.print(b);
      } else {
        sum = 0;
        a = a * 10 + (customKey - '0');
        lcd.print(a);
      }
      break;

    case '-': case '+': case 'x': case '/':
      if(sum != 0) {
        a = sum;
      }
      op = true;
      oper = customKey;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(a);
      lcd.print(oper);
      break;
    
    case 'AC':
      lcd.clear();
      lcd.setCursor(0,0);
      sum = 0;
      a = 0;
      b = 0;
      op = false;

    case '=':
      op = false;
      if(b == 0) {
        if(oper == 'x' || oper == '/'){
          sum = 0;
        } else {
          sum = a;
        }
      } else {
        switch(oper) {
          case '-':
            sum = a - b;
            break;
          case '+':
            sum = a + b;
            break;
          case 'x':
            sum = a * b;
            break;
          case '/':
            sum = a / b;
            break;
        }
      }
      Serial.println(sum);
      lcd.setCursor(0,1);
      lcd.print("= ");
      lcd.print(sum);
      a = 0;
      b = 0;
      break;
  }
}

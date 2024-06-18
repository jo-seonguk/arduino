#include <TM1637Display.h>

#define CLK 8    // 클럭 포트

#define DIO 9     // 데이터 입력 포트

TM1637Display  display(CLK, DIO);

int i, j, k;
uint8_t data[] =  { 0xff, 0xff, 0xff, 0xff };
uint8_t blank[] = { 0x00, 0x00, 0x00, 0x00 };
uint8_t count[] = {  0xff, 0xff, 0xff, 0xff  };

const uint8_t SEG_LOVE[] = {        // 우측 FND 이미지 참조
  SEG_D | SEG_E | SEG_F,                             // L
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,     // O
  SEG_B | SEG_E | SEG_F | SEG_G,                     // V
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G   };         // E

const uint8_t SEG_DONE[] = {

  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,             // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,     // O
  SEG_C | SEG_E | SEG_G,                             // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G      };      // E

void setup() {
  display.setBrightness(7);                // 0~7, 밝기 조절 
  display.setSegments(data);  //배열 출력(FND로 8888 비트 모두가 출력된다)
  delay(1000);

   // ##### [ 0~F 출력하기] #####
   // encode digit를 이용해서 배열 내용을 변경해 넣을 수 있다
  // 0 ~ 9는 숫자로 10 ~ 15까지는 알파벳 A ~ F로 출력된다
  // encodeDigit(x)의 x는 0~15 입력으로 숫자 0부터 알파벳 F까지만 표시가능

  data[0] = display.encodeDigit(0);
  data[1] = display.encodeDigit(1);
  data[2] = display.encodeDigit(2);
  data[3] = display.encodeDigit(3);
  display.setSegments(data);      // 위 숫자 0~3의 배열값 한번에 출력
  delay(1000);

  data[0] = display.encodeDigit(4);
  data[1] = display.encodeDigit(5);
  data[2] = display.encodeDigit(6);
  data[3] = display.encodeDigit(7);
  display.setSegments(data); //위 숫자 4~7의 배열값 한번에 출력
  delay(1000);

  data[0] = display.encodeDigit(8);
  data[1] = display.encodeDigit(9);
  data[2] = display.encodeDigit(0);
  data[3] = display.encodeDigit(0);
  display.setSegments(data); //위 숫자 8,9,0,0 배열값 한번에 출력
  delay(2000);

  data[0] = display.encodeDigit(10);
  data[1] = display.encodeDigit(11);
  data[2] = display.encodeDigit(12);
  data[3] = display.encodeDigit(13);
  display.setSegments(data);  //위 10~13값에 해당하는 A~d 출력
  delay(1000);

  data[0] = display.encodeDigit(14);  // 'E' 출력
  data[1] = display.encodeDigit(15);  // 'F' 출력
  data[2] = display.encodeDigit(16); //'F'다음은 다시0부터 반복
  data[3] = display.encodeDigit(17); // '1' 출력
  display.setSegments(data);     delay(2000);   //  E F 0 1 출력



//#### [ showNumberDec 함수 이용하여 다양하게 표시해보기] ####
  display.showNumberDec(1318, false, 4, 0);    //숫자 값 직접 출력할 경우
  // 1318 : 표시할 숫자 , 4 : 표시숫자 길이, 0 : 표시할 위치(맨좌측부터 0123)
  delay(1000);

  display.showNumberDec(567, false, 3, 1);      delay(2000);
  //아래처럼 옵션에 숫자 3자리만 출력하고 2번째('1')digit부터 표시 할 경우, 기존
  // 출력된 숫자 등은 그대로 표시됨. 따라서 위 기존 출력'1318'에서 '1'이 계속 표시
  // 되어, '1567'이 최종 출력됨. 567 :표시할 숫자 , 3 :숫자 길이, 1 :표시할 위치

  display.showNumberDec(0, false);   delay(1000);     // 출력 : ___0

  display.showNumberDec(0, true);     delay(1000);     // 출력 : 0000

  display.showNumberDec(1, false);    delay(1000);     // Expect: ___1

  display.showNumberDec(1, true);      delay(1000);    // Expect: 0001

  display.showNumberDec(301, false); delay(1000);    // Expect: _301

  display.showNumberDec(301, true);   delay(1000);      // Expect: 0301

  display.showNumberDec(14, false, 2, 1); delay(1000); // Expect: _14_

  display.showNumberDec(4, true, 2, 2); delay(1000);   // Expect: 04__

  display.showNumberDec(-1, false);      delay(1000);  // Expect: __-1

  display.showNumberDec(-12);            delay(1000);   // Expect: _-12

  display.showNumberDec(-999);           delay(1000);   // Expect: -999

 // ##### [ 시계표시를 위한 '도트' 출력 하기  ] #####
  for(int j=0; j <= 2; j++) {
    for(int k=0; k <= 4; k++) {
      display.showNumberDecEx(0, (0x80 >> k), true); 
  // showNumberDecEx(표시할 숫자, 도트출력, 0일때 '0'자체 표시 유무)
      delay(500);    // 돗트가 꺼지고(500)켜지는(500)시간 총합한 1초 간격
     }
   }



// ##### [ 밝기 테스트 : 1~7 단계  ] #####

  for(int k = 0; k < 4; k++)

    data[k] = 0xff;

  for(int k = 0; k < 7; k++) {

    display.setBrightness(k);

    display.setSegments(data);

    delay(800);

  }

// ##### [ 모듈 켜고 끄기 test  ] #####

  for(k = 0; k < 3; k++) {

    display.setBrightness(7, false);     // 겨기

    display.setSegments(data);

    delay(500);

    display.setBrightness(7, true);       // 끄기

    display.setSegments(data);

    delay(500); 

  }



//##### [ 0부터 ~ F까지 좌로 시프트 시키기 (2회 반복)] #####

for (i = 0; i <= 1; i++)  {                 // 2회 반복

    for(k = 0; k <= 12; k++) {           // 12까지 하면 F까지 출력가능

      for(j =0; j <= 3; j++) {             // 한번에 숫자 4개 출력해야함

        count[j] = display.encodeDigit(j+k);     //배열에 값 넣기

        display.setSegments(count);               //배열값 출력

        delay(20);

      }

      delay(250);

    } 

Filter your search...
Type:

All




    delay(2000);

  }

//#### [배열로 알파벳 만들어 출력하기(앞 부분 배열선언 참조)] ###

  display.setSegments(SEG_LOVE);      // LOVE 출력

  delay(1000);

  display.setSegments(SEG_DONE);      // dOnE 출력
}

void loop() {
  // put your main code here, to run repeatedly:

}

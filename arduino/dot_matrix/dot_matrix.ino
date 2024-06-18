int rows[] = {-1, 10, 11, 12, 13, 14, 15, 16, 17};
int cols[] = {-2, 2, 3, 4, 5, 6, 7, 8, 9};


void setup() {
  // put your setup code here, to run once:
  for(int i=1; i<9; i++) {              
    pinMode(cols[i], OUTPUT);
    pinMode(rows[i], OUTPUT);
  }

}


void loop() {
  for(int i=1; i<9; i++) {
    digitalWrite(rows[i], HIGH);
    digitalWrite(cols[i], LOW);
    delay(500);
    clear();
  }
}

void clear() {
  for(int i = 1; i<9; i++) {
    digitalWrite(rows[i], LOW);
  }
}
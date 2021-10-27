#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int changeButton = 13;
const int moveButton = 10;
const char chars[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','.',',','1','2','3','4','5','6','7','8','9','0','-','*','@', ' '};

int charsIndex = 0;
int changeButtonState = 0;
int moveButtonState = 0;
int resetButtonState = 0;
int charsSize = 0;
int cx = 0;
int cy = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.blink();
  
  charsSize = sizeof(chars);
  
  pinMode(changeButton, INPUT);
  pinMode(moveButton, INPUT);
  
}

void loop() {
  changeButtonState = digitalRead(changeButton);
  moveButtonState = digitalRead(moveButton);
  
  if (changeButtonState == HIGH) {
    if (charsIndex == charsSize) {
      charsIndex = 0;
    }
    
    lcd.print(chars[charsIndex]);
    lcd.setCursor(cx,cy);
    charsIndex ++;
  } else if (moveButtonState == HIGH) {
    charsIndex = 0;
    cx ++;
    
    if (cx == 16) {
      cx = 0;
      cy ++;
    }
    
    if (cy == 2){
      cy = 0;
    }

    lcd.setCursor(cx,cy);
  } 
  
  delay(340);
}

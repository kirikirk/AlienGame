#include <LiquidCrystal.h>
const int buttonPin = 8;   
char gameName[] = {'A','l','i','e','n','G','a','m','e'};
bool buttonState = false;
bool playing = false;
LiquidCrystal lcd(13, 11, 5, 4, 3, 6);
byte alien[8] = {
  B01110,
  B11101,
  B11101,
  B11111,
  B11100,
  B11111,
  B10101,
  B10101,
};

byte gnd[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
};

byte gnd2[8] = {
  B11111,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

byte gnd1[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B01110,
  B11111,
};

void drawLoading(){
  lcd.clear();
  if(playing) return;
  lcd.setCursor(0,0);
  lcd.write("LOADING");
  
}

void drawAll(){
  lcd.setCursor(0,1);
  for(int i = 0; i < 16; i++){
    delay(100);
    lcd.write(byte(1));
  }
  
  lcd.setCursor(0,0);
  
  for(int i = 0; i < 16; i++){
    delay(100);
    lcd.write(byte(3));
  }
}
void startGame(){
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.write("start");
}

void drawStartPage(){
  for(int i = 0; i < 9; i++){
    lcd.setCursor(i + 3,0);
    lcd.write(' ');
    delay(300);
    lcd.setCursor(3,0);
    lcd.write(gameName);
    delay(300);
  }
}

void buttonPush (){
  buttonState = true;
  playing = true;
}

void setup() {
  pinMode(2, INPUT);
  pinMode(buttonPin, INPUT);
  lcd.begin(16, 2);
  lcd.createChar(3, gnd2);
  lcd.createChar(1, gnd);
  lcd.createChar(0, alien);
  lcd.setCursor(3,1);
  lcd.write(byte(0));
  lcd.createChar(2, gnd1);
  lcd.setCursor(3,0);
  attachInterrupt(0, buttonPush, FALLING  );
  drawLoading();
  playing = false;
}

void loop() {
  if(!playing){
    drawStartPage();
  }else{
    drawLoading();  
    while(playing){
      delay (500);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.write("playing");
    }
  }
}

#include <Keypad.h>
#include <LiquidCrystal.h>


const int rs = 14, en = 15, d4 = 16, d5 = 17, d6 = 19, d7 = 20;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'C','0','=','+'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


String option1 = "Reisi";
String option2 = "rEisi";
String option3 = "reIsi";
int option1_votes = 0;
int option2_votes = 0;
int option3_votes = 0;

void setup() {
  lcd.begin(20, 4);
  Serial.begin(9600);
  lcd.print("        OFF         ");
  pinMode(23, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
  digitalWrite(28, HIGH);
  digitalWrite(29, LOW);

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);
  pinMode(A7, OUTPUT);
  pinMode(A8, OUTPUT);
  pinMode(A9, OUTPUT);
  pinMode(A13, OUTPUT);
  pinMode(A14, OUTPUT);
  pinMode(A15, OUTPUT);
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A5, LOW);
  digitalWrite(A6, LOW);
  digitalWrite(A7, LOW);
  digitalWrite(A8, LOW);
  digitalWrite(A9, LOW);
  digitalWrite(A13, LOW);
  digitalWrite(A14, LOW);
  digitalWrite(A15, LOW);
}

void loop() {
  if( Serial.available() ){
    int winner = Serial.read() - 48;
    digitalWrite(28, LOW);
    digitalWrite(29, HIGH);
    tone(23, 1000, 100);
    lcd.clear();
    lcd.print("  Polling is Over!  ");
    lcd.setCursor(0, 1);
    lcd.print("   The Winner is    ");
    if( winner == 1 ){
      lcd.setCursor(0,2);
      lcd.print("1. ");
      lcd.print(option1);
    }
    if( winner == 2 ){
      lcd.setCursor(0,2);
      lcd.print("2. ");
      lcd.print(option2);
    }
    if( winner == 3 ){
      lcd.setCursor(0,2);
      lcd.print("3. ");
      lcd.print(option3);
    }
    while( 1 ){
        digitalWrite(A0, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A0, LOW);
        digitalWrite(A1, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A1, LOW);
        digitalWrite(A2, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A2, LOW);
        digitalWrite(A3, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A3, LOW);
        digitalWrite(A7, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A7, LOW);
        digitalWrite(A6, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A6, LOW);
        digitalWrite(A5, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A5, LOW);
        digitalWrite(A4, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A4, LOW);
        digitalWrite(A8, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A8, LOW);
        digitalWrite(A9, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A9, LOW);
        digitalWrite(A13, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A13, LOW);
        digitalWrite(A14, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A14, LOW);
        digitalWrite(A15, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A15, LOW);
        digitalWrite(A14, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A14, LOW);
        digitalWrite(A13, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A13, LOW);
        digitalWrite(A9, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A9, LOW);
        digitalWrite(A8, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A8, LOW);
        digitalWrite(A4, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A4, LOW);
        digitalWrite(A5, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A5, LOW);
        digitalWrite(A6, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A6, LOW);
        digitalWrite(A7, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A7, LOW);
        digitalWrite(A3, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A3, LOW);
        digitalWrite(A2, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A2, LOW);
        digitalWrite(A1, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A1, LOW);
        digitalWrite(A0, HIGH);
        if( keypad.getKey() == '-' ) break;
        delay(40);
        digitalWrite(A0, LOW); 
      }
      digitalWrite(A0, LOW);
      digitalWrite(A1, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);
      digitalWrite(A5, LOW);
      digitalWrite(A6, LOW);
      digitalWrite(A7, LOW);
      digitalWrite(A8, LOW);
      digitalWrite(A9, LOW);
      digitalWrite(A13, LOW);
      digitalWrite(A14, LOW);
      digitalWrite(A15, LOW);
      digitalWrite(28, HIGH);
      digitalWrite(29, LOW);
      tone(23, 1000, 100);
      lcd.clear();
      lcd.print("        OFF         ");
      option1_votes = 0;
      option2_votes = 0;
      option3_votes = 0;
  }

  
  char key = keypad.getKey();
  if( key == '+' ){
    digitalWrite(28, LOW);
    digitalWrite(29, HIGH);
    tone(23, 1000, 100);
    again:
    lcd.clear();
    lcd.print("     Which One?     ");
    lcd.setCursor(0,1);
    lcd.print("1. ");
    lcd.print(option1);
    lcd.setCursor(0,2);
    lcd.print("2. ");
    lcd.print(option2);
    lcd.setCursor(0,3);
    lcd.print("3. ");
    lcd.print(option3);
    key = keypad.waitForKey();
    if( key == '1' ){
      lcd.clear();
      lcd.print("1.Confirm");
      lcd.setCursor(0, 1);
      lcd.print("2.Change");
      key = keypad.waitForKey();
      if( key == '1' ){
        lcd.clear();
        lcd.print("       Thanks       ");
        lcd.setCursor(0, 1);
        lcd.print("You voted for  ");
        lcd.setCursor(0, 2);
        lcd.print("1. ");
        lcd.print(option1);
        option1_votes++;
        Serial.print("1");
        delay(200);
      }
      goto again;
    }
    else if( key == '2' ){
      lcd.clear();
      lcd.print("1.Confirm");
      lcd.setCursor(0, 1);
      lcd.print("2.Change");
      key = keypad.waitForKey();
      if( key == '1' ){
        lcd.clear();
        lcd.print("       Thanks       ");
        lcd.setCursor(0, 1);
        lcd.print("You voted for  ");
        lcd.setCursor(0, 2);
        lcd.print("2. ");
        lcd.print(option2);
        option2_votes++;
        Serial.print("2");
        delay(200);
      }
      goto again;
    }
    else if( key == '3' ){
      lcd.clear();
      lcd.print("1.Confirm");
      lcd.setCursor(0, 1);
      lcd.print("2.Change");
      key = keypad.waitForKey();
      if( key == '1' ){
        lcd.clear();
        lcd.print("       Thanks       ");
        lcd.setCursor(0, 1);
        lcd.print("You voted for  ");
        lcd.setCursor(0, 2);
        lcd.print("3. ");
        lcd.print(option3);
        option3_votes++;
        Serial.print("3");
        delay(200);
      }
      goto again;
    }
    else if( key == '-' ){
    digitalWrite(28, HIGH);
    digitalWrite(29, LOW);
    tone(23, 1000, 100);
    lcd.clear();
    lcd.print("        OFF         ");
    }
    else if( key == '*' ){
      lcd.clear();
      lcd.print("    TodayResult:    ");
      lcd.setCursor(0, 1);
      lcd.print("1. ");
      lcd.print(String(option1_votes));
      lcd.setCursor(0,2);
      lcd.print("2. ");
      lcd.print(String(option2_votes));
      lcd.setCursor(0,3);
      lcd.print("3. ");
      lcd.print(String(option3_votes));
      delay(500);
      goto again;
    }
    else{
      goto again;
    }
  }
  
}

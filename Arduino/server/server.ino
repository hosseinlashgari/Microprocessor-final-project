#include <Keypad.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>


const int rs = 22, en = 24, d4 = 25, d5 = 26, d6 = 27, d7 = 30;
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
int option1_votes;
int option2_votes;
int option3_votes;


void setup() {
  lcd.begin(20, 4);
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);
  lcd.print("        OFF         ");
  pinMode(23, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
  digitalWrite(28, HIGH);
  digitalWrite(29, LOW);
}

void loop() {
  if( Serial.available() ){
    int vote1 = Serial.read() - 48;
    if( vote1 == 1 ){
      option1_votes = EEPROM.read(0);
      if( option1_votes == 255 ) option1_votes = 0;
      option1_votes++;
      EEPROM.write(0, option1_votes);
      delay(10);
    }
    if( vote1 == 2 ){
      option2_votes = EEPROM.read(1);
      if( option2_votes == 255 ) option2_votes = 0;
      option2_votes++;
      EEPROM.write(1, option2_votes);
      delay(10);
    }
    if( vote1 == 3 ){
      option3_votes = EEPROM.read(2);
      if( option3_votes == 255 ) option3_votes = 0;
      option3_votes++;
      EEPROM.write(2, option3_votes);
      delay(10);
    }
  }

  if( Serial1.available() ){
    int vote2 = Serial1.read() - 48;
    if( vote2 == 1 ){
      option1_votes = EEPROM.read(3);
      if( option1_votes == 255 ) option1_votes = 0;
      option1_votes++;
      EEPROM.write(3, option1_votes);
      delay(10);
    }
    if( vote2 == 2 ){
      option2_votes = EEPROM.read(4);
      if( option2_votes == 255 ) option2_votes = 0;
      option2_votes++;
      EEPROM.write(4, option2_votes);
      delay(10);
    }
    if( vote2 == 3 ){
      option3_votes = EEPROM.read(5);
      if( option3_votes == 255 ) option3_votes = 0;
      option3_votes++;
      EEPROM.write(5, option3_votes);
      delay(10);
    }
  }

  if( Serial2.available() ){
    int vote3 = Serial2.read() - 48;
    if( vote3 == 1 ){
      option1_votes = EEPROM.read(6);
      if( option1_votes == 255 ) option1_votes = 0;
      option1_votes++;
      EEPROM.write(6, option1_votes);
      delay(10);
    }
    if( vote3 == 2 ){
      option2_votes = EEPROM.read(7);
      if( option2_votes == 255 ) option2_votes = 0;
      option2_votes++;
      EEPROM.write(7, option2_votes);
      delay(10);
    }
    if( vote3 == 3 ){
      option3_votes = EEPROM.read(8);
      if( option3_votes == 255 ) option3_votes = 0;
      option3_votes++;
      EEPROM.write(8, option3_votes);
      delay(10);
    }
  }

  
  if( Serial3.available() ){
    int vote4 = Serial3.read() - 48;
    if( vote4 == 1 ){
      option1_votes = EEPROM.read(9);
      if( option1_votes == 255 ) option1_votes = 0;
      option1_votes++;
      EEPROM.write(9, option1_votes);
      delay(10);
    }
    if( vote4 == 2 ){
      option2_votes = EEPROM.read(10);
      if( option2_votes == 255 ) option2_votes = 0;
      option2_votes++;
      EEPROM.write(10, option2_votes);
      delay(10);
    }
    if( vote4 == 3 ){
      option3_votes = EEPROM.read(11);
      if( option3_votes == 255 ) option3_votes = 0;
      option3_votes++;
      EEPROM.write(11, option3_votes);
      delay(10);
    }
  }


  char key = keypad.getKey();
  if( key == '+' ){
    digitalWrite(28, LOW);
    digitalWrite(29, HIGH);
    tone(23, 1000, 100);
    again:
    lcd.clear();
    lcd.print("Which Device Result?");
    lcd.setCursor(0,1);
    lcd.print("Enter 0to4/ 0: Total");
    lcd.setCursor(0,2);
    lcd.print("-TurnOff =Terminate");
    lcd.setCursor(0,3);
    lcd.print("C EraseMemory  ");
    key = keypad.waitForKey();
    if( key == '1' ){
        lcd.clear();
        lcd.print("  Device 1 Result:  ");
        lcd.setCursor(0, 1);
        lcd.print("1. ");
        lcd.print(EEPROM.read(0));
        lcd.setCursor(0, 2);
        lcd.print("2. ");
        lcd.print(EEPROM.read(1));
        lcd.setCursor(0, 3);
        lcd.print("3. ");
        lcd.print(EEPROM.read(2));
        delay(500);
        goto again;
    }
    else if( key == '2' ){
        lcd.clear();
        lcd.print("  Device 2 Result:  ");
        lcd.setCursor(0, 1);
        lcd.print("1. ");
        lcd.print(EEPROM.read(3));
        lcd.setCursor(0, 2);
        lcd.print("2. ");
        lcd.print(EEPROM.read(4));
        lcd.setCursor(0, 3);
        lcd.print("3. ");
        lcd.print(EEPROM.read(5));
        delay(500);
        goto again;
    }
    else if( key == '3' ){
        lcd.clear();
        lcd.print("  Device 3 Result:  ");
        lcd.setCursor(0, 1);
        lcd.print("1. ");
        lcd.print(EEPROM.read(6));
        lcd.setCursor(0, 2);
        lcd.print("2. ");
        lcd.print(EEPROM.read(7));
        lcd.setCursor(0, 3);
        lcd.print("3. ");
        lcd.print(EEPROM.read(8));
        delay(500);
        goto again;
    }
    else if( key == '4' ){
        lcd.clear();
        lcd.print("  Device 4 Result:  ");
        lcd.setCursor(0, 1);
        lcd.print("1. ");
        lcd.print(EEPROM.read(9));
        lcd.setCursor(0, 2);
        lcd.print("2. ");
        lcd.print(EEPROM.read(10));
        lcd.setCursor(0, 3);
        lcd.print("3. ");
        lcd.print(EEPROM.read(11));
        delay(500);
        goto again;
    }
    else if( key == '0' ){
        lcd.clear();
        lcd.print("   Total Result:    ");
        lcd.setCursor(0, 1);
        lcd.print("1. ");
        int total1 = EEPROM.read(0)+EEPROM.read(3)+EEPROM.read(6)+EEPROM.read(9);
        delay(10);
        lcd.print(total1);
        lcd.setCursor(0, 2);
        lcd.print("2. ");
        int total2 = EEPROM.read(1)+EEPROM.read(4)+EEPROM.read(7)+EEPROM.read(10);
        delay(10);
        lcd.print(total2);
        lcd.setCursor(0, 3);
        lcd.print("3. ");
        int total3 = EEPROM.read(2)+EEPROM.read(5)+EEPROM.read(8)+EEPROM.read(11);
        delay(10);
        lcd.print(total3);
        delay(500);
        goto again;
    }
    else if( key == '-' ){
      digitalWrite(28, HIGH);
      digitalWrite(29, LOW);
      tone(23, 1000, 100);
      lcd.clear();
      lcd.print("        OFF         ");
    }
    else if( key == '=' ){
        int total1 = EEPROM.read(0)+EEPROM.read(3)+EEPROM.read(6)+EEPROM.read(9);
        int total2 = EEPROM.read(1)+EEPROM.read(4)+EEPROM.read(7)+EEPROM.read(10);
        int total3 = EEPROM.read(2)+EEPROM.read(5)+EEPROM.read(8)+EEPROM.read(11);

        int winner_num;
        int winner = -1;
        if( total1 > total2 ) {
          winner = total1;
          winner_num = 1;
        }
        else if ( total2 > total1 ) {
          winner = total2;
          winner_num = 2;
        }
        if( winner == -1 ) {
          if( total3 > total1 ) {
            winner = total3;
            winner_num = 3;
          }
        }
        else {
          if ( total3 > winner ) {
            winner = total3;
            winner_num = 3;
          }
          else if ( total3 == winner ) winner = -1;
        }
        if( winner == -1 ){
          lcd.clear();
          lcd.print("       Draw!     ");
          lcd.setCursor(0,1);
          lcd.print("There is not Winner");
          lcd.setCursor(0,2);
          lcd.print("  Continue Polling  ");
        }
        else{
          lcd.clear();
          lcd.print(" Result Published!  ");
          Serial.print(winner_num);
          Serial1.print(winner_num);
          Serial2.print(winner_num);
          Serial3.print(winner_num);
          EEPROM.write(0, 0);
          EEPROM.write(1, 0);
          EEPROM.write(2, 0);
          EEPROM.write(3, 0);
          EEPROM.write(4, 0);
          EEPROM.write(5, 0);
          EEPROM.write(6, 0);
          EEPROM.write(7, 0);
          EEPROM.write(8, 0);
          EEPROM.write(9, 0);
          EEPROM.write(10, 0);
          EEPROM.write(11, 0);
        }
        delay(300);
        goto again;
    }
    else if( key == 'C' ){
      lcd.clear();
      lcd.print("Erase Which Device?");
      lcd.setCursor(0,1);
      lcd.print("Enter 0to4/ 0: Total");
      lcd.setCursor(0,2);
      lcd.print("    '-' to Cancel    ");
      key = keypad.waitForKey();
      if( key == '1' ){
          EEPROM.write(0, 0);
          EEPROM.write(1, 0);
          EEPROM.write(2, 0);
          lcd.clear();
          lcd.print("  Device 1 Erased   ");
          tone(23, 1000, 100);
          delay(200);
          goto again;
      }
      else if( key == '2' ){
          EEPROM.write(3, 0);
          EEPROM.write(4, 0);
          EEPROM.write(5, 0);
          lcd.clear();
          lcd.print("  Device 2 Erased   ");
          tone(23, 1000, 100);
          delay(200);
          goto again;
      }
      else if( key == '3' ){
          EEPROM.write(6, 0);
          EEPROM.write(7, 0);
          EEPROM.write(8, 0);
          lcd.clear();
          lcd.print("  Device 3 Erased  ");
          tone(23, 1000, 100);
          delay(200);
          goto again;
      }
      else if( key == '4' ){
          EEPROM.write(9, 0);
          EEPROM.write(10, 0);
          EEPROM.write(11, 0);
          lcd.clear();
          lcd.print("  Device 4 Erased   ");
          tone(23, 1000, 100);
          delay(200);
          goto again;
      }
      else if( key == '0' ){
          EEPROM.write(0, 0);
          EEPROM.write(1, 0);
          EEPROM.write(2, 0);
          EEPROM.write(3, 0);
          EEPROM.write(4, 0);
          EEPROM.write(5, 0);
          EEPROM.write(6, 0);
          EEPROM.write(7, 0);
          EEPROM.write(8, 0);
          EEPROM.write(9, 0);
          EEPROM.write(10, 0);
          EEPROM.write(11, 0);
          lcd.clear();
          lcd.print(" All Devices Erased ");
          tone(23, 1000, 100);
          delay(200);
          goto again;
      }
      else{
          goto again;
      }
    }
    else{
      goto again;
    }
  }

}

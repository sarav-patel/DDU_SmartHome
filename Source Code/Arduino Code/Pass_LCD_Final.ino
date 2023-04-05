/*
  The circuit:
 * LCD RS pin to digital pin 34
 * LCD Enable pin to digital pin 35
 * LCD D4 pin to digital pin 36
 * LCD D5 pin to digital pin 37
 * LCD D6 pin to digital pin 38
 * LCD D7 pin to digital pin 39
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
*/
 
//# is to validate password   
//* is to reset password attempt

#define MAX_ALLOWED_ATTEMPTS 3
#include <Password.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

int attempts = 0;
Password password = Password( "1234" );

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {22, 23, 24, 25};
byte colPins[COLS] = {26, 27, 28, 29};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

LiquidCrystal lcd(34, 35, 36, 37, 38, 39);

void setup()
{

  Serial.begin(9600);
  lcd.begin(16, 2);
  
  keypad.addEventListener(keypadEvent);
  
  pinMode(30,OUTPUT);
  pinMode(31,OUTPUT);
  digitalWrite(30,HIGH);
  digitalWrite(31,LOW);

  lcd.setCursor(0,0);
  lcd.print("Ent Pass : ");
}

void loop()
{
  keypad.getKey();
}

void keypadEvent(KeypadEvent eKey)
{
  switch (keypad.getState())
  {
    case PRESSED:
      Serial.print("Pressed: ");
      Serial.println(eKey);
      lcd.setCursor(11,0);
      lcd.print(eKey);
      switch (eKey)
      {
        case '#': checkPassword(); break;
        case '*': password.reset(); pinnormal(); lcdnormal();break;
        default: password.append(eKey);
     }
  }
}

void checkPassword()
{
  if (password.evaluate())
  {
    Serial.println("Success");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Welcome To Your");
    lcd.setCursor(0,1);
    lcd.print("      Home      ");
    //Add code to run if it works
    pinright();
    delay(5000);

    password.reset();
    pinnormal();
    lcdnormal();
    attempts = 0;
  }
  else
  {
    Serial.println("Wrong");
    lcd.setCursor(0,1);
    lcd.print("Wrg");
    //add code to run if it did not work
    attempts += 1;

    if(attempts == MAX_ALLOWED_ATTEMPTS)
    {
      Serial.println("Max Attempts");
      pinwrong();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(" Your Photo Is ");
      lcd.setCursor(0,1);
      lcd.print("  Sent To Owner ");
      delay(5000);
      pinnormal();
      lcdnormal();
      attempts = 0;
    }
    else
    {
      Serial.print("Attempts Remaining : ");
      Serial.println(MAX_ALLOWED_ATTEMPTS - attempts);
      lcd.print("-Atmt Lft : ");
      lcd.print(MAX_ALLOWED_ATTEMPTS - attempts); 
      password.reset();
      pinnormal();
    }
  }
}

void pinnormal()
{
  digitalWrite(30,HIGH);
  digitalWrite(31,LOW);
}

void pinright()
{
  digitalWrite(30,HIGH);
  digitalWrite(31,HIGH);
}

void pinwrong()
{
  digitalWrite(30,LOW);
  digitalWrite(31,LOW);
}

void lcdnormal()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ent Pass : ");
}



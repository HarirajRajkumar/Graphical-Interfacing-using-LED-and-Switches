
/*
 * This following program allows user to Control LEDs using switches and LED interfacing
 * Move LCD cursor by using LEFT , RIGHT switches and select to Turn ON or OFF using using SELECT button
 * 
 */
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const byte myLed[4] = {A0 , A1 , A2 , A3};
boolean LEDstate[4] = {1 , 1 , 1 ,1 };
// Declaring pin
const byte SwitchLEFT = 6;
const byte SwitchRIGHT = 7;
const byte SelectPIN = 8;
// LEDs


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(SwitchLEFT , INPUT);
  pinMode(SwitchLEFT , INPUT_PULLUP);
  pinMode(SwitchRIGHT , INPUT_PULLUP);
  pinMode(SelectPIN , INPUT_PULLUP);
  // LED declarations
  for(byte i=0; i<=3;i++)
  {
  pinMode(myLed[i] , OUTPUT);
  digitalWrite(myLed[i] , HIGH);
  }
  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("[1] [2] [3] [4] ");

  for(byte i=0; i<=3;i++)
  {
  delay(100);
  digitalWrite(myLed[i] , LOW);
  }
  
}// close setup

int LEFTdata = 0;
int RIGHTdata = 0;
byte Horizontal_data = 1;
byte SelectData = 0;

void loop()
{
  
  // set the cursor to (0,0):
    LEFTdata =  digitalRead(SwitchLEFT);
    RIGHTdata = digitalRead(SwitchRIGHT);
    SelectData = digitalRead(SelectPIN);
    
   //Serial.print(LEFTdata);
   //Serial.print("\t");
   //Serial.print(RIGHTdata);
   //Serial.print("\t");

  
    lcd.setCursor(Horizontal_data,0);
    lcd.blink();

    if(RIGHTdata == LOW && Horizontal_data != 13) 
   {
    Horizontal_data += 4;
    delay(200);
   }// close if

    if(LEFTdata == LOW && Horizontal_data != 1)
    {
      Horizontal_data -= 4;
      delay(200);
    }// close if

   //Serial.print(Horizontal_data);
   //Serial.print("\t\t");
   //Serial.print("\n");
if(SelectData == LOW)
{
   switch(Horizontal_data)
   {
    case 1 : 
    Serial.print("LED1");
    Serial.print("\n");
    
    LEDstate[0] =! LEDstate[0];
    delay(100);
    digitalWrite(myLed[0] ,LEDstate[0]);
    break;

    case 5 :
    Serial.print("LED2");
    Serial.print("\n");
  
    LEDstate[1] =! LEDstate[1];
    delay(100);
    digitalWrite(myLed[1] ,LEDstate[1]);
    break;

    case 9 :
    Serial.print("LED3");
    Serial.print("\n");
    
    LEDstate[2] =! LEDstate[2];
    delay(100);
    digitalWrite(myLed[2] ,LEDstate[2]);
    break;

    case 13 :
    Serial.print("LED4");
    Serial.print("\n");
    LEDstate[3] =! LEDstate[3];
    delay(100);
    digitalWrite(myLed[3] ,LEDstate[3]);

    break;

   }// close switch
} //close if
}// close loop  

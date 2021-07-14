#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'.', '0', '=', '/'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

long Num1,Num2,Number;
char key,action;
boolean result = false;

void setup(){
  Serial.begin(9600);
}
  
void loop() {
  
key = customKeypad.getKey(); //storing pressed key value in a char

//if (key!=NO_KEY)
DetectButtons();

if (result==true){
CalculateResult();

DisplayResult();  } 
}

void DetectButtons()
{ 
    if (key=='.') //If cancel Button is pressed
    { Number=Num1=Num2=0; result=false;}
    
     if (key == '1') //If Button 1 is pressed
    { 
    if (Number==0)
    Number=1;
    else
    Number = (Number*10) + 1; //Pressed twice
    }
    
     if (key == '4') //If Button 4 is pressed
    {
    if (Number==0)
    Number=4;
    else
    Number = (Number*10) + 4; //Pressed twice
    }
    
     if (key == '7') //If Button 7 is pressed
    {
    if (Number==0)
    Number=7;
    else
    Number = (Number*10) + 7; //Pressed twice
    } 
  

    if (key == '0')
    {
    if (Number==0)
    Number=0;
    else
    Number = (Number*10) + 0; //Pressed twice
    }
    
     if (key == '2') //Button 2 is Pressed
    {
     if (Number==0)
    Number=2;
    else
    Number = (Number*10) + 2; //Pressed twice
    }
    
     if (key == '5')
    {
     if (Number==0)
    Number=5;
    else
    Number = (Number*10) + 5; //Pressed twice
    }
    
     if (key == '8')
    {
     if (Number==0)
    Number=8;
    else
    Number = (Number*10) + 8; //Pressed twice
    }   
  

    if (key == '=')
    {
    Num2=Number;
    result = true;
    }
    
     if (key == '3')
    {
     if (Number==0)
    Number=3;
    else
    Number = (Number*10) + 3; //Pressed twice
    }
    
     if (key == '6')
    {
    if (Number==0)
    Number=6;
    else
    Number = (Number*10) + 6; //Pressed twice
    }
    
     if (key == '9')
    {
    if (Number==0)
    Number=9;
    else
    Number = (Number*10) + 9; //Pressed twice
    }  

      if (key == '+' || key == '-' || key == '*' || key == '/') //Detecting Buttons on Column 4
  {
    Num1 = Number;    
    Number =0;
    if (key == '+')
    {action = '+';}
     if (key == '-')
    {action = '-'; }
     if (key == '*')
    {action = '*';}
     if (key == '/')
    {action = '/';}  

    delay(100);
  }
  
}

void CalculateResult()
{
  if (action=='+')
    Number = Num1+Num2;

  if (action=='-')
    Number = Num1-Num2;

  if (action=='*')
    Number = Num1*Num2;

  if (action=='/')
    Number = Num1/Num2; 
}

void DisplayResult()
{
  Serial.print(Num1); Serial.print(action); Serial.print(Num2); 
  
  if (result==true)
  {Serial.print(" ="); Serial.print(Number);} //Display the result
  Serial.println(" ");
  delay(1000);
  result=false;
}

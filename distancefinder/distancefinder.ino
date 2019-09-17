
#include "LCD_Launchpad.h"



#define RS 8
#define RW 9
#define EN 7
#define D4 6
#define D5 5
#define D6 4
#define D7 3

#define ECHO 17
#define TEST 40
#define TRIGGER 33


float distance=0;
float tempo=1;
LCD_LAUNCHPAD lcd;
 
void setup()
{
 // Serial.begin(9600); 

  lcd.init();
  
  pinMode(TRIGGER,OUTPUT);
  pinMode(ECHO,INPUT);  
  //lcd.begin(16,2);
  delay(1000);
  lcd.clear();
  //lcd.print("Distance Meter");
   delay(1000);
}

void loop()
{
  lcd.clear();
  delayMicroseconds(50);
  digitalWrite(TRIGGER,LOW);
  delayMicroseconds(20);
  digitalWrite(TRIGGER,HIGH);
  delayMicroseconds(200);
  digitalWrite(TRIGGER,LOW);
  delayMicroseconds(20);
  tempo=pulseIn(ECHO,HIGH);
  //lcd.print("distance meter");
  

  distance=tempo*340/20000;
  //Serial.println(distance);
  
  delayMicroseconds(50);
  lcd.clear();
  delayMicroseconds(50);
  

  
  //if(distance<401)
  //{
    lcd.println(distance);
    
    
  //}
  
  delay(1000);
  
}

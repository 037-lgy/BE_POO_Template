//#include "Application.h"
//#include <LiquidCrystal.h>
//#include "LCD.h"

//Application myApplication;

void setup() 
{
  //myApplication.init();
  Serial.begin(9600);
  pinMode(D7, OUTPUT);
  Serial.println("LED test");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  //myApplication.run();
  digitalWrite(D7,HIGH);
  delay(500);
  digitalWrite(D7,LOW);
  delay(500);
  
}

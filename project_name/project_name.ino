#include "Application.h"
#include <LiquidCrystal.h>
#include "LCD.h"

Application myApplication;

void setup() 
{
  // put your setup code here, to run once:
  myApplication.init();
  //pinMode(0,OUTPUT);
  //pinMode(5,INPUT);
  //pinMode(12,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  myApplication.run();
  
}

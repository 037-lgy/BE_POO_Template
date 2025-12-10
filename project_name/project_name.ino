#include "Application.h"
//Application myApplication;

void setup() 
{
  // put your setup code here, to run once:
  //myApplication.init();
  pinMode(0,OUTPUT);
  pinMode(5,INPUT);
  pinMode(12,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  //myApplication.run();
  digitalWrite(12,HIGH);
  a = digitalRead(1);
  printf(a);
  /*
  if (digitalRead(1)){
    pinMode(0,LOW);
    a = digitalRead(1);
  }
  else{
    pinMode(0,LOW);
  }
  */
}

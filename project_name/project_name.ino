#include "Application.h"
#include "LCD.h"

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
  etat = digitalRead(D5);
  if (etat == HIGH) digitalWrite(D7, LOW);
  else digitalWrite(D7,HIGH);
}
#include "Application.h"
#include "LCD.h"

Application myApplication;
int etat = 0;
int etat1 = 0;

void setup() 
{
  // put your setup code here, to run once:
  //myApplication.init();
  Serial.begin(9600);
  pinMode(D7,OUTPUT);
  pinMode(D5,INPUT);
  Serial.println("led init");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  //myApplication.run();
  etat = digitalRead(D5);
  if (etat == HIGH) digitalWrite(D7, LOW);
  else digitalWrite(D7,HIGH);
}

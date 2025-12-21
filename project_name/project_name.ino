#include "Application.h"
#include "LCD.h"

Application myApplication;

void setup() 
{
  myApplication.init();
  //Serial.begin(9600);
  //pinMode(D6, INPUT_PULLUP);
  //pinMode(D8, INPUT_PULLUP);
  //pinMode(D9, OUTPUT);
  //Serial.println("Test LED + Bouton pret");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  myApplication.run();
  // int bouton = digitalRead(D3);
  // long sum = 0;
  // for(int i=0; i<32; i++) {
  //   sum += analogRead(A0);
  // }
  // sum >>= 5;
  // Serial.println(sum);
  // delay(500);
}
#include "LED.h"

LED::LED(String name, uint8_t pin):Single_pin_actuators(name,pin){}

LED::~LED(){

}

void LED::initialisation(){
  pinMode(pin,OUTPUT);
  digitalWrite(pin,LOW);
  Serial.print("Initialisation de la led : ");
  Serial.println(nom);
}
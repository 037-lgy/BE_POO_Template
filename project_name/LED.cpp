#include "LED.h"

LED::LED(String name, uint8_t pin):Actuators(name,pin){
  state = LOW;
}

LED::~LED(){

}

void LED::initialisation(){
  pinMode(pin,OUTPUT);
  digitalWrite(pin,LOW);
  while(!Serial.isTxEnabled()){}
  Serial.print("Initialisation de la led : ");
  Serial.println(nom);
}

void LED::update(){
  digitalWrite(pin, state);
}

void LED::set_on(){
  state = HIGH;
}

void LED::set_off(){
  state = LOW;
}

void LED::toggle(){
  if (state == HIGH) state = LOW;
  else state = HIGH;
}
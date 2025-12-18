#include "LED.h"

LED::LED(String name, uint8_t pin):Actuators(name,pin){
  state = LOW;
}

LED::~LED(){

}

void LED::initialisation(){
  pinMode(getpin(),OUTPUT);
  digitalWrite(getpin(),LOW);
  Serial.println("Initialisation de la led : ");
  Serial.println(getnom());
}

void LED::update(){
  digitalWrite(getpin(), state);
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
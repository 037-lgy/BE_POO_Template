#include "Onebit_Actuators.h"

Onebit_Actuators::Onebit_Actuators(String name, uint8_t pin):Actuators(name,pin){
  state = LOW;
}

Onebit_Actuators::~Onebit_Actuators(){

}

void Onebit_Actuators::update(){
  digitalWrite(getpin(), state);
}

void Onebit_Actuators::set_on(){
  state = HIGH;
}

void Onebit_Actuators::set_off(){
  state = LOW;
}

void Onebit_Actuators::toggle(){
  if (state == HIGH) state = LOW;
  else state = HIGH;
}

uint8_t Onebit_Actuators::getstate(){
  return state;
}
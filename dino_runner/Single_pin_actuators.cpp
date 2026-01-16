#include "Single_pin_actuators.h"

Single_pin_actuators::Single_pin_actuators(String name, uint8_t pin):Actuators(name,pin){
  state = LOW;
}

Single_pin_actuators::~Single_pin_actuators(){

}

void Single_pin_actuators::update(){
  digitalWrite(pin, state);
}

void Single_pin_actuators::set_on(){
  state = HIGH;
}

void Single_pin_actuators::set_off(){
  state = LOW;
}

void Single_pin_actuators::toggle(){
  if (state == HIGH) state = LOW;
  else state = HIGH;
}

uint8_t Single_pin_actuators::getstate(){
  return state;
}
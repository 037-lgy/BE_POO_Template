#include <stdint.h>
#include "Buzzer.h"

Buzzer::Buzzer(String name, uint8_t pin):Actuators(name,pin){
  state = LOW;
}

Buzzer::~Buzzer(){

}

void Buzzer::initialisation(){
  pinMode(getpin(),OUTPUT);
  digitalWrite(getpin(),LOW);
  Serial.print("Initialisation du buzzer : ");
  Serial.println(getnom());
}

void Buzzer::update(){
  digitalWrite(getpin(), state);
}

void Buzzer::set_on(){
  state = HIGH;
}

void Buzzer::set_off(){
  state = LOW;
}

void Buzzer::toggle(){
  state ^= 1;
}
#include "Buzzer.h"

Buzzer::Buzzer(String name, uint8_t pin):Single_pin_actuators(name,pin){}

Buzzer::~Buzzer(){

}

void Buzzer::initialisation(){
  pinMode(pin,OUTPUT);
  digitalWrite(pin,LOW);
  Serial.print("Initialisation du buzzer : ");
  Serial.println(nom);
}
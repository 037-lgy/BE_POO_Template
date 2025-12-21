#include "Potentiometre.h"

Potentiometre::Potentiometre(String name, uint8_t pin):Sensors(name, pin){
  state = LOW;
}

Potentiometre::~Potentiometre(){

}

void Potentiometre::initialisation(){
  pinMode(pin,INPUT);
  Serial.print("Initialisation du potentiometre : ");
  Serial.println(nom);
}

uint16_t Potentiometre::readsensor(){
  for(int i=0; i<32; i++) {
    state += analogRead(A0);
  }
  state >>= 5;
  return state;
}
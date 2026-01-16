#include "Button.h"

Button::Button(String name, uint8_t pin):Sensors(name,pin){
  state = LOW;
}

Button::~Button(){

}

void Button::initialisation(){
  pinMode(pin,INPUT);
  Serial.print("Initialisation du bouton : ");
  Serial.println(nom);
}

uint16_t Button::readsensor(){
  state = digitalRead(pin);
  return state;
}

bool Button::issame(){
  return (state == digitalRead(pin));
}
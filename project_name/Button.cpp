#include "Button.h"

Button::Button(String name, uint8_t pin):Sensors(name,pin){
  state = LOW;
}

Button::~Button(){

}

void Button::initialisation(){
  pinMode(getpin(),INPUT);
  Serial.print("Initialisation du bouton : ");
  Serial.println(getnom());
}

uint16_t Button::readsensor(){
  state = digitalRead(getpin());
  return state;
}

bool Button::issame(){
  return (state == digitalRead(getpin()));
}
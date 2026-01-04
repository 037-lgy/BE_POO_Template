#include "core_esp8266_features.h"
#include "Dino.h"

Dino::Dino(uint8_t* tab, int x, int y):Game_Object(tab, x, y),isjumping(false),jumptime((unsigned long)0),landtime((unsigned long)0),islanding(false){}

Dino::~Dino(){

}

void Dino::jump(){
  if (!isjumping){
    if (!islanding){
      isjumping = true;
      x = 0;
      jumptime = millis();
    }
  }
}

void Dino::update_pos_basic(int Intensity){
  if (isjumping){
    if ((millis() - jumptime) >= 500){
      isjumping = false;
      islanding = true;
      landtime = millis();
      x = 1;
    }
  }
  else if (islanding){
    if ((millis() - landtime >= 200)){
      islanding = false;
    }
  }
}

bool Dino::getisjumping(){
  return isjumping;
}

void Dino::reset(int x, int y){
  this->x = x;
  this->y = y;
  islanding = false;
  isjumping = false;
  landtime = 0;
  jumptime = 0;
}
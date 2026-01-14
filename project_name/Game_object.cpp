#include "Game_object.h"

uint8_t dark[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

Game_Object::Game_Object(uint8_t* tab, int x, int y):full_shape(tab),x(x),y(y), currentshape(tab){}

Game_Object::~Game_Object(){
  
}

void Game_Object::setpos(int x, int y){
  this->x = x;
  this->y = y;
}

int Game_Object::getx(){
  return x;
}

int Game_Object::gety(){
  return y;
}

uint8_t* Game_Object::getshape(){
  return this->currentshape;
}

void Game_Object::changeshape(uint8_t *tab){
  this->currentshape = tab;
}
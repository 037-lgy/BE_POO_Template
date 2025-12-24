#include "Game_object.h"

Game_Object::Game_Object(uint8_t* tab, int x, int y):shape(tab),x(x),y(y){}

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
  return this->shape;
}

void Game_Object::changeshape(uint8_t *tab){
  this->shape = tab;
}
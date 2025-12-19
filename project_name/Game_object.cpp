#include "Game_object.h"

Game_Object::Game_Object(std::array<std::array<bool, 6>, 8> tab, int x, int y):shape(tab),x(x),y(y){}

Game_Object::~Game_Object(){

}

void Game_Object::setpos(int x, int y){
  this->x = x;
  this->y = y;
}
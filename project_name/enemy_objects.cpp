#include "Enemy_objects.h"

Enemy_objects::Enemy_objects(uint8_t* tab, int x, int y):Game_Object(tab, x, y),isgoingleft(false), gotime((unsigned long)0){}

Enemy_objects::~Enemy_objects(){
  
}

void Enemy_objects::update_pos_basic(int Intensity){
  if (y >= 0 ) {
    if (!isgoingleft){
      currentshape = full_shape;
      isgoingleft = true;
      gotime = millis();
      y--;
    }
    else if (millis() - gotime >= Intensity){
      isgoingleft = false;
    }
  }
  else {
    isgoingleft = false;
  }
}

void Enemy_objects::spawn(int x, int y){
  this->x = x;
  this->y = y;
  isgoingleft = false;
}

void Enemy_objects::reset(int x, int y){
  this->x = x;
  this->y = y;
  isgoingleft = false;
  gotime = 0;
}
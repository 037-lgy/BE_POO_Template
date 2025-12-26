#include "enemy_objects.h"

Enemy_objects::Enemy_objects(uint8_t* tab, int x, int y):Game_Object(tab, x, y),isgoingleft(false), gotime((unsigned long)0){}

Enemy_objects::Enemy_objects(uint8_t* shape, uint8_t* left_shape, uint8_t* right_shape, int x, int y):
  Game_Object(shape, x, y),left_shape(left_shape),right_shape(right_shape), isgoingleft(false), gotime((unsigned long)0), state((int)0){}


void Enemy_objects::spawn(int x){
  this->x = x;
  y = 15;
  isgoingleft = false;
}

void Enemy_objects::update_pos(){
  if (!isgoingleft){
    if (y >= 0 ) {
      if (state == 0) currentshape = right_shape;
      else if (state == 1) currentshape = full_shape;
      else if (state == 2) currentshape = left_shape;
      state++;
      if (state > 2) {
        state = 0;
        y--;
      }
      isgoingleft = true;
      gotime = millis();
    }
  }
  else if (millis() - gotime >= 2000){
    isgoingleft = false;
  }
}
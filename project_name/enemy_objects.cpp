#include "enemy_objects.h"

Enemy_objects::Enemy_objects(uint8_t* tab, int x, int y):Game_Object(tab, x, y),isgoingleft(false), gotime((unsigned long)0){}


void Enemy_objects::spawn(int x){
  this->x = x;
  y = 15;
  isgoingleft = false;
}

void Enemy_objects::update_pos(){
  if (!isgoingleft){
    if (y > 0 ) {
      y--;
      isgoingleft = true;
      gotime = millis();
    }
    else {
      y = -1;
    }
  }
  else if (millis() - gotime >= 200){
    isgoingleft = false;
  }
}

void Enemy_objects::split(){
  
}
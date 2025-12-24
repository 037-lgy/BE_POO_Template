#include "Bird.h"

Bird::Bird(uint8_t* tab, int x, int y):Game_Object(tab, x, y){}

Bird::~Bird(){

}

void Bird::spawn(int x){
  this->x = x;
  y = 15;
  isgoingleft = false;
}

void Bird::update_pos(){
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
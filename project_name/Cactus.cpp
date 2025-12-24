#include "Cactus.h"

Cactus::Cactus(uint8_t* tab, int x, int y):Game_Object(tab, x, y), isgoingleft(false), gotime((unsigned long)0){}

Cactus::~Cactus(){

}

void Cactus::apparition(){
  x = 1;
  y = 15;
}

void Cactus::update_pos(){
  if (!isgoingleft){
    isgoingleft = true;
    gotime = millis();
    if (y > 0 ) y--;
    else y = 15;
  }
  else if (millis() - gotime >= 200){
    isgoingleft = false;
  }
}
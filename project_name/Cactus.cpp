#include "Cactus.h"

Cactus::Cactus(uint8_t* tab, int x, int y):Game_Object(tab, x, y), isgoingleft(false), gotime((unsigned long)0){}

Cactus::~Cactus(){

}

void Cactus::apparition(){
  x = 1;
  y = 15;
}

void Cactus::goleft(){
  if(!isgoingleft){
    isgoingleft = true;
    gotime = millis();
    if (y > 0) y--;
    else y = 15; // Voir qu'est-ce qu'il se passe pour l'objet à la fin
  }
}

void Cactus::update_left(){
  if (isgoingleft){
    if ((millis() - gotime) >= 500){
      isgoingleft = false;
    }
  }
}
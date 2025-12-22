#include "Dino.h"

Dino::Dino(std::array<uint8_t, 8>& tab, int x, int y):Game_Object(tab, x, y){}

Dino::~Dino(){

}

void Dino::jump(){
  if(x = 1) x--;
}
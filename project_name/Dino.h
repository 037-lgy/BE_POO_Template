#ifndef DINO_H_
#define DINO_H_

#include "Game_Object.h"
#include <Arduino.h>

class Dino : public Game_Object{
  public :
    Dino(uint8_t* tab, int x, int y);
    ~Dino();
    void jump();
    void avoid();
};

#endif
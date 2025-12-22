#ifndef DINO_H_
#define DINO_H_

#include "Game_Object.h"
#include <Arduino.h>
#include <array>

class Dino : public Game_Object{
  public :
    Dino(std::array<uint8_t, 8>& tab, int x, int y);
    ~Dino();
    void jump();
    void avoid();
};

#endif
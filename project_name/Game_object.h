#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <array>
#include <Arduino.h>

class Game_Object{
  protected:
    std::array<uint8_t, 8> shape;
    int x;
    int y;
  public:
    Game_Object(std::array<uint8_t, 8>& tab, int x, int y);
    ~Game_Object();
    void setpos(int x, int y);
    std::array<uint8_t, 8> getshape(); //getteur de la forme de l'objet
};

#endif
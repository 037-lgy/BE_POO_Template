#ifndef CACTUS_H_
#define CACTUS_H_

#include "Game_Object.h"

class Cactus : public Game_Object{
  private:
    bool isgoingleft;
    unsigned long gotime;
  public:
    Cactus(uint8_t* tab, int x, int y);
    ~Cactus();
    void goleft();
    void update_left();
    void update_pos(); // Pas besoin de update left et goleft je pense, seulement celle ci mais à checker en réel
    void apparition();
};

#endif
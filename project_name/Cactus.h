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
    void apparition();
};

#endif
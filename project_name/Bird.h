#include <stdint.h>
#ifndef BIRD_H_
#define BIRD_H_

#include "Game_object.h"

class Bird : public Game_Object{
  private:
    bool isgoingleft;
    unsigned long gotime;
  public:
    Bird(uint8_t* tab, int x, int y);
    ~Bird();
    void spawn(int x);
    void update_pos();
};

#endif
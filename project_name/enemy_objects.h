#include <stdint.h>
#ifndef ENEMY_OBJECTS
#define ENEMY_OBJECTS

#include "Game_object.h"

class Enemy_objects : public Game_Object{
  protected:
    bool isgoingleft;
    unsigned long gotime;
  public:
    Enemy_objects(uint8_t* tab, int x, int y);
    ~Enemy_objects();
    void update_pos();
    void update_pos_basic(int Intensity = -1);
    void spawn(int x, int y);
    void reset(int x, int y);
};

#endif
#include <stdint.h>
#ifndef ENEMY_OBJECTS
#define ENEMY_OBJECTS

#include "Game_object.h"

class Enemy_objects : public Game_Object{
  protected:
    bool isgoingleft;
    unsigned long gotime;
    uint8_t split1[8];
    uint8_t split2[8];
  public:
    Enemy_objects(uint8_t* tab, int x, int y);
    ~Enemy_objects();
    void update_pos();
    void spawn(int x);
    virtual void split();
};

#endif
#include <stdint.h>
#ifndef ENEMY_OBJECTS
#define ENEMY_OBJECTS

#include "Game_object.h"

class Enemy_objects : public Game_Object{
  protected:
    bool isgoingleft;
    unsigned long gotime;
    uint8_t* left_shape;
    int state;
  public:
    Enemy_objects(uint8_t* tab, int x, int y);
    Enemy_objects(uint8_t* shape, uint8_t* left_shape, int x, int y);
    ~Enemy_objects();
    void update_pos();
    void update_pos_basic();
    void spawn(int x);
};

#endif
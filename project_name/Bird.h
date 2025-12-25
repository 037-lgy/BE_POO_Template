#include <stdint.h>
#ifndef BIRD_H_
#define BIRD_H_

#include "enemy_objects.h"

class Bird : public Enemy_objects{
  public:
    Bird(uint8_t* tab, int x, int y);
    ~Bird();
};

#endif
#ifndef BIRD_H_
#define BIRD_H_

#include "enemy_objects.h"

extern uint8_t bird[8];
extern uint8_t blackbird[8];

class Bird : public Enemy_objects{
  public:
    Bird();  
};

#endif
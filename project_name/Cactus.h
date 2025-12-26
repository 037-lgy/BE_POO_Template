#include <stdint.h>
#ifndef CACTUS_H_
#define CACTUS_H_

#include "Enemy_objects.h"

class Cactus : public Enemy_objects{
  public:
    Cactus(uint8_t* tab, int x, int y);
    ~Cactus();
};

#endif
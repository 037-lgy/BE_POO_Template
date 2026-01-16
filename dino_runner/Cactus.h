#ifndef CACTUS_H_
#define CACTUS_H_

#include "enemy_objects.h"

extern uint8_t cactus[8];
extern uint8_t blackcactus[8];

class Cactus : public Enemy_objects{
  public:
    Cactus();

    /**
     *@fn void reset()
     *@brief reset la position de l'objet dans le lcd
     *@details doit être définie par les classes filles
    */
    void reset();
};

#endif
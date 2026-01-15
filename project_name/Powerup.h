#ifndef POWER_UP_H_
#define POWER_UP_H_

#include "enemy_objects.h"

extern uint8_t powerup[8];
extern uint8_t blackpowerup[8];

class Power_up : public Enemy_objects{
  public:
    Power_up();

    /**
     *@fn void reset()
     *@brief reset la position de l'objet dans le lcd
     *@details doit être définie par les classes filles
    */
    void reset(); 
};

#endif
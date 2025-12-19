#ifndef ACTUATORS_H_
#define ACTUATORS_H_

#include <Arduino.h>
#include "Device.h"

class Actuators : public Device{
  public:
    Actuators(String name, uint8_t pin);
    ~Actuators();
    virtual void update()= 0; //Mettre à jour l'actionneur
};

#endif
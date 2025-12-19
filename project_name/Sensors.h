#ifndef SENSORS_H_
#define SENSORS_H_

#include "Device.h"

class Sensors : public Device{
  public:
    Sensors(String name, uint8_t pin);
    ~Sensors();
    virtual uint16_t readsensor()= 0; //Lire l'état du capteur
};

#endif
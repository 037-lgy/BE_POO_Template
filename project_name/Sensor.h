#ifndef SENSOR_H_
#define SENSOR_H_

#include "Device.h"

class Sensor : public Device{
  public:
    Sensor(String name, uint8_t pin);
    ~Sensor();
    virtual void readsensor()= 0;
};

#endif
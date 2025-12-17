#ifndef SENSOR_H_
#define SENSOR_H_

#include "Device.h"

class Sensor : public Device{
  public:
    Sensor(String name);
    ~Sensor();
    virtual void readsensor()= 0;
};

#endif
#ifndef Device_H_
#define Device_H_

#include <Arduino.h>

class Device{
  private:
    String nom;
    uint8_t pin;
  public:
    static int nb_device;
    Device(String name, uint8_t pin);
    ~Device();
    String getnom();
    uint8_t getpin();
    virtual void initialisation()= 0;
};

#endif
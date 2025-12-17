#ifndef Device_H_
#define Device_H_

#include <Arduino.h>

class Device{
  private:
    String nom;
  public:
    static int nb_device;
    Device(String name);
    ~Device();
    String getnom();
    virtual void initialisation()= 0;
};

#endif
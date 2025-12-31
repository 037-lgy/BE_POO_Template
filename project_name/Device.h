#ifndef Device_H_
#define Device_H_

#include <Arduino.h>

class Device{
  protected:
    String nom;
    uint8_t pin;
    static int nb_devices;
  public:
    Device(String name, uint8_t pin);
    ~Device();
    String getnom(); //Récupérer le nom du device
    uint8_t getpin(); //Récupérer le pin associé au device
    int getnbdevices();
    virtual void initialisation()= 0; //Initialiser le device
};

#endif
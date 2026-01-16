#ifndef SENSORS_H_
#define SENSORS_H_

#include "Device.h"

class Sensors : public Device{
  public:
    /**
     *@fn Sensors(String name, uint8_t pin);
     *@brief Constructeur de la classe Sensors
     *@param name nom à donner au capteur
     *@param pin broche du gpio de l'arduino
    */
    Sensors(String name, uint8_t pin);

    /**
     *@fn ~Sensors()
     *@brief Destructeur de la classe Sensors
    */
    ~Sensors();

    /**
     *@fn virtual uint16_t readsensor()= 0
     *@brief lit l'état matériel du capteur
     *@return uint16_t l'état du capteur =
     *@details doit être définie par les classes filles
    */
    virtual uint16_t readsensor()= 0;
};

#endif
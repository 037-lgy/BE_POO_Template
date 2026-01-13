#ifndef ACTUATORS_H_
#define ACTUATORS_H_

#include <Arduino.h>
#include "Device.h"

class Actuators : public Device{
  public:

    /**
     *@fn Actuators(String name, uint8_t pin)
     *@brief Constructeur de la classe Actuators
     *@param name nom à donner à l'actionneur
     *@param pin broche du gpio de l'arduino
    */
    Actuators(String name, uint8_t pin);

    /**
     *@fn ~Actuators()
     *@brief Destructeur de la classe Actuators
    */
    ~Actuators();

    /**
     *@fn virtual void update()= 0
     *@brief met à jour l'état de l'actionneur
     *@details doit être définie par les classes filles
    */
    virtual void update()= 0;
};

#endif
#ifndef ONEBIT_ACTUATORS_H_
#define ONEBIT_ACTUATORS_H_

#include "Actuators.h"

class Single_pin_actuators : public Actuators{
  protected:
    uint8_t state;
  public:
    Single_pin_actuators(String name, uint8_t pin);
    ~Single_pin_actuators();
    void update();
    void set_on(); //Allumer l'actionneur
    void set_off(); //Eteindre l'actionneur
    void toggle(); // Changer l'état de l'actionneur
    uint8_t getstate(); //getteur de l'état de l'actionneur
};

#endif
#ifndef ONEBIT_ACTUATORS_H_
#define ONEBIT_ACTUATORS_H_

#include "Actuators.h"

class Onebit_Actuators : Actuators{
  protected:
    uint8_t state;
  public:
    Onebit_Actuators(String name, uint8_t pin);
    ~Onebit_Actuators();
    void initialisation();
    void update();
    void set_on(); //Allumer l'actionneur
    void set_off(); //Eteindre l'actionneur
    void toggle(); // Changer l'état de l'actionneur
    uint8_t getstate(); //getteur de l'état de l'actionneur
};

#endif
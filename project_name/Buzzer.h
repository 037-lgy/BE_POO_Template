#include <stdint.h>
#include <sys/types.h>
#ifndef BUZZER_H_
#define BUZZER_H_

#include "Single_pin_actuators.h"

class Buzzer : public Single_pin_actuators{
  private:
    uint8_t state;
  public:
    /**
     *@fn Buzzer(String name, uint8_t pin)
     *@brief Constructeur de la classe Buzzer
     *@param name nom à donner au buzzer
     *@param pin broche du gpio de l'arduino
    */
    Buzzer(String name, uint8_t pin);

    /**
     *@fn ~Buzzer()
     *@brief Destructeur de la classe Buzzer
    */
    ~Buzzer();

    /**
     *@fn void initialisation()
     *@brief Initialise l'état du buzzer matériellemnt, à l'état bas en OUTPUT
    */
    void initialisation();
};

#endif
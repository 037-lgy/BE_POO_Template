#ifndef LED_H_
#define LED_H_

#include "Single_pin_actuators.h"

class LED : public Single_pin_actuators{
  public:
    /**
     *@fn LED(String name, uint8_t pin)
     *@brief Constructeur de la classe LED
     *@param name nom à donner à la led
     *@param pin broche du gpio de l'arduino
    */
    LED(String name, uint8_t pin);

    /**
     *@fn ~LED()
     *@brief Destructeur de la classe LED
    */
    ~LED();

    /**
     *@fn void initialisation()
     *@brief Initialise l'état de la LED matériellemnt, à l'état bas en OUTPUT
    */
    void initialisation();
};

#endif
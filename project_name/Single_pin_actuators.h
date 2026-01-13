#ifndef ONEBIT_ACTUATORS_H_
#define ONEBIT_ACTUATORS_H_

#include "Actuators.h"

class Single_pin_actuators : public Actuators{
  protected:
    uint8_t state;
  public:
    /**
     *@fn Single_pin_actuators(String name, uint8_t pin)
     *@brief Constructeur de la classe Single_pin_actuators
     *@param name nom à donner au périphérique
     *@param pin broche du gpio de l'arduino
    */
    Single_pin_actuators(String name, uint8_t pin);

    /**
     *@fn ~Single_pin_actuators()
     *@brief Destructeur de la classe Single_pin_actuators
    */
    ~Single_pin_actuators();

    /**
     *@fn void update()
     *@brief met à jour matériellement l'état de la broche de l'actionneur en fonction de la variable state
    */
    void update();

    /**
     *@fn void set_on()
     *@brief met la variable state de cette classe à '1'
    */
    void set_on();

    /**
     *@fn void set_off()
     *@brief met la variable state de cette classe à '0'
    */
    void set_off();

    /**
     *@fn void toggle()
     *@brief inverse l'état de la variable state
    */
    void toggle();

    /**
     *@fn uint8_t getstate()
     *@brief retourn l'état de la variable state
     *@return state état de l'actionneur
    */
    uint8_t getstate();
};

#endif
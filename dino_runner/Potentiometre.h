#ifndef POTENTIOMETRE_H_
#define POTENTIOMETRE_H_

#include "Sensors.h"

class Potentiometre : public Sensors{
  private:
    uint16_t state;
  public:
    /**
     *@fn Potentiometre(String name, uint8_t pin);
     *@brief Constructeur de la classe Potentiometre
     *@param name nom à donner au Potentiometre
     *@param pin broche du gpio de l'arduino (seul A0 est possible en analogique)
    */
    Potentiometre(String name, uint8_t pin);

    /**
     *@fn ~Potentiometre()
     *@brief Destructeur de la classe Potentiometre
    */
    ~Potentiometre();

    /**
     *@fn void initialisation()
     *@brief Initialise l'état du bouton matériellemnet, en mode INPUT
    */
    void initialisation();

    /**
     *@fn uint16_t readsensor()
     *@brief lit l'état matériel analogique du capteur
     *@return uint16_t la valeur de la variable state
    */
    uint16_t readsensor();
};

#endif;
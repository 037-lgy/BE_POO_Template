#ifndef BUTTON_H_
#define BUTTON_H_

#include "Sensors.h"

class Button : public Sensors{
  private:
    uint16_t state;
  public:
    /**
     *@fn Button(String name, uint8_t pin);
     *@brief Constructeur de la classe Button
     *@param name nom à donner au bouton
     *@param pin broche du gpio de l'arduino
    */
    Button(String name, uint8_t pin);

    /**
     *@fn ~Button()
     *@brief Destructeur de la classe Button
    */
    ~Button();

    /**
     *@fn void initialisation()
     *@brief Initialise l'état du bouton matériellement, en mode INPUT
    */
    void initialisation();

    /**
     *@fn uint16_t readsensor()
     *@brief lit l'état matériel numérique du capteur
     *@return uint16_t la valeur de la variable state
    */
    uint16_t readsensor();

    /**
     *@fn bool issame()
     *@brief cherche à savoir s'il y a eu un changement d'état par rapport à la variable state et l'état matériel du capteur
     *@return bool '0' si changement d'état il y a
    */
    bool issame(); //Détecter un changement d'état du bouton
};

#endif
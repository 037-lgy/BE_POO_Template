#ifndef BUTTON_H_
#define BUTTON_H_

#include "Sensors.h"

class Button : public Sensors{
  private:
    uint16_t state;
  public:
    Button(String name, uint8_t pin);
    ~Button();
    void initialisation();
    uint16_t readsensor();
    bool issame(); //Détecter un changement d'état du bouton
};

#endif
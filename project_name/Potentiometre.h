#ifndef POTENTIOMETRE_H_
#define POTENTIOMETRE_H_

#include "Sensors.h"

class Potentiometre : public Sensors{
  private:
    uint16_t state;
  public:
    Potentiometre(String name, uint8_t pin);
    ~Potentiometre();
    void initialisation();
    uint16_t readsensor();
};

#endif;
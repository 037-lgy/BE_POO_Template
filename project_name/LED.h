#ifndef LED_H_
#define LED_H_

#include "Actuators.h"

class LED : public Actuators{
  private:
    uint8_t state;
  public:
    LED(String name, uint8_t pin);
    ~LED();
    void initialisation();
    void update();
    void set_on();
    void set_off();
    void toggle();
};

#endif
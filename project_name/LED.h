#ifndef LED_H_
#define LED_H_

#include "Single_pin_actuators.h"

class LED : public Single_pin_actuators{
  public:
    LED(String name, uint8_t pin);
    ~LED();
    void initialisation();
};

#endif
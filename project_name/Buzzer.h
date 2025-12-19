#include <stdint.h>
#include <sys/types.h>
#ifndef BUZZER_H_
#define BUZZER_H_

#include "Actuators.h"

class Buzzer : public Actuators{
  private:
    uint8_t state;
  public:
    Buzzer(String name, uint8_t pin);
    ~Buzzer();
    void initialisation();
    void update();
    void set_on();
    void set_off();
    void toggle();
};

#endif
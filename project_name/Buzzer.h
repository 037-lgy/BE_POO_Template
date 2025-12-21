#include <stdint.h>
#include <sys/types.h>
#ifndef BUZZER_H_
#define BUZZER_H_

#include "Single_pin_actuators.h"

class Buzzer : public Single_pin_actuators{
  private:
    uint8_t state;
  public:
    Buzzer(String name, uint8_t pin);
    ~Buzzer();
    void initialisation();
};

#endif
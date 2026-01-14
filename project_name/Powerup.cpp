#include "Powerup.h"

uint8_t powerup[8] = {
  0b00111,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

uint8_t blackpowerup[8] = {
  0b11000,
  0b11000,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

Power_up::Power_up():Enemy_objects(powerup, 0, -1){

}
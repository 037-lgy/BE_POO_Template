#include <stdint.h>
#include "Bird.h"

Bird::Bird(uint8_t* tab, int x, int y):Enemy_objects(tab, x, y){
  static const uint8_t bird_mid_left[8] = {
  0b10000, // #
  0b10000, // #
  0b10000, // #
  0b11100, // ###
  0b11000, // ##
  0b10000, // #
  0b00000, //
  0b00000 //
  };
  static const uint8_t bird_mid_right[8] = {
  0b00001, //     #
  0b00001, //     #
  0b00101, //   # #
  0b00111, //   ###
  0b00011, //    ##
  0b00001, //     #
  0b00000, //
  0b00000 //
  };
  memcpy(this->split1, bird_mid_left, 8);
  memcpy(this->split2, bird_mid_right, 8);
}

Bird::~Bird(){

}
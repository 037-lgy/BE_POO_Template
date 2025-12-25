#include "Cactus.h"

Cactus::Cactus(uint8_t* tab, int x, int y):Enemy_objects(tab, x, y){
  static const uint8_t cactus_mid_left[8] = {
  0b10000, // #
  0b10000, // #
  0b10000, // #
  0b10100, // # #
  0b11100, // ###
  0b10000, // #
  0b10000, // #
  0b10000 //  #
  };

static const uint8_t cactus_mid_right[8] = {
  0b00001, //     #
  0b00001, //     #
  0b00011, //    ##
  0b00111, //   ###
  0b00111, //   ###
  0b00001, //     #
  0b00001, //     #
  0b00001 //      #
  };
  memcpy(this->split1, cactus_mid_left, 8);
  memcpy(this->split2, cactus_mid_right, 8);
}

Cactus::~Cactus(){

}
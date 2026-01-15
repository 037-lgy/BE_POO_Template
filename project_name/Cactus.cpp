#include "Cactus.h"

uint8_t cactus[8] = {
  0b00100, //   #
  0b00100, //   #
  0b01100, //  ##
  0b11101, // ### #
  0b11111, // #####
  0b00100, //   #
  0b00100, //   #
  0b00100  //   #
};

uint8_t blackcactus[8] = {
  0b11011, //
  0b11011, //
  0b10011, //
  0b00010, //
  0b00000, //
  0b11011, //
  0b11011, //
  0b11011  //
};

Cactus::Cactus():Enemy_objects(cactus, 1, -1){
  identity = danger;
}
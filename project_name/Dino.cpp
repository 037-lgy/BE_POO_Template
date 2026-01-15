#include "core_esp8266_features.h"
#include "Dino.h"

uint8_t dinodino[8] = {
  0b00000,
  0b00111, //   ###
  0b00101, //   # #
  0b00111, //   ###
  0b00100, //   #
  0b11110, // ####
  0b01010, //  # #
  0b01010  //  # #
};


uint8_t blackdinodino[8] = {
  0b11111,
  0b11000, //   ###
  0b11010, //   # #
  0b11000, //   ###
  0b11011, //   #
  0b00001, // ####
  0b10101, //  # #
  0b10101  //  # #
};

uint8_t dinoflip[8] = {
  0b01010, //  # # 
  0b01010, //  # # 
  0b11110, // #### 
  0b00100, //   # 
  0b00111, //   ###
  0b00101, //   # #
  0b00111, //   ###
  0b00000
};

uint8_t blackdinoflip[8] = {
  0b10101, //  # # 
  0b10101, //  # # 
  0b00001, // #### 
  0b11011, //   # 
  0b11000, //   ###
  0b11010, //   # #
  0b11000, //   ###
  0b11111
};

uint8_t dinodinolyingdown[8] = {
  0b00000,
  0b00000, //
  0b00000, //
  0b00000, //
  0b00000, //
  0b11111, // #####
  0b10101, // # # #
  0b10111  // # ###
};

uint8_t blackdinodinolyingdown[8] = {
  0b11111,
  0b11111, //
  0b11111, //
  0b11111, //
  0b11111, //
  0b00000, // #####
  0b01010, // # # #
  0b01000  // # ###
};

Dino::Dino(uint8_t* tab, int x, int y):Game_Object(tab, x, y),isjumping(false),jumptime((unsigned long)0),landtime((unsigned long)0),islanding(false){
  identity = dinosaur;
}

Dino::~Dino(){

}

void Dino::jump(){
  if (!isjumping){
    if (!islanding){
      isjumping = true;
      x = 0;
      jumptime = millis();
    }
  }
}

void Dino::update_pos_basic(int Intensity){
  if (isjumping){
    if ((millis() - jumptime) >= 500){
      isjumping = false;
      islanding = true;
      landtime = millis();
      x = 1;
    }
  }
  else if (islanding){
    if ((millis() - landtime >= 200)){
      islanding = false;
    }
  }
}

bool Dino::getisjumping(){
  return isjumping;
}

void Dino::reset(int x, int y){
  this->x = x;
  this->y = y;
  islanding = false;
  isjumping = false;
  landtime = 0;
  jumptime = 0;
}
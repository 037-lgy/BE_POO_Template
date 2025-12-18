#include "Device.h"

int Device::nb_device = 0;

Device::Device(String name, uint8_t PIN):nom(name),pin(PIN){}

Device::~Device(){
  nb_device--;
}

String Device::getnom() {
  return nom;
}

uint8_t Device::getpin() {
  return pin;
}
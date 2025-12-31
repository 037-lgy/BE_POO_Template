#include "Device.h"

int Device::nb_devices = 0;

Device::Device(String name, uint8_t PIN):nom(name),pin(PIN){
  nb_devices++;
}

Device::~Device(){
  nb_devices--;
}

String Device::getnom() {
  return nom;
}

uint8_t Device::getpin() {
  return pin;
}

int Device::getnbdevices(){
  return nb_devices;
}
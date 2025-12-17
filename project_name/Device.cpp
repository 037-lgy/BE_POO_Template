#include "Device.h"

int Device::nb_device = 0;

Device::Device(String name):nom(name){}

Device::~Device(){
  nb_device--;
}

String Device::getnom() {
  return nom;
}
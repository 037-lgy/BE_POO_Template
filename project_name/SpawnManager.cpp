#include "core_esp8266_features.h"
#include "SpawnManager.h"

SpawnManager::SpawnManager():spawndelaymode1((int)4000),spawndelaymode2((int)800){
  harderdelay = millis();
}

SpawnManager::~SpawnManager(){

}

void SpawnManager::resetspawn(){
  spawndelaymode1 = 4000;
}

void SpawnManager::harder(){
  if (((millis() - harderdelay) > 500) && spawndelaymode1 > 1000) {
    spawndelaymode1 -= 100;
    harderdelay = millis();
  }
}

const int SpawnManager::getspawndelaymode1(){
  return spawndelaymode1;
}

const int SpawnManager::getspawndelaymode2(){
  return spawndelaymode2;
}

void SpawnManager::setharderdelay(){
  harderdelay = millis();
}
#include "core_esp8266_features.h"
#include "DifficultyManager.h"

DifficultyManager::DifficultyManager():spawndelaymode1((int)4000),spawndelaymode2((int)800),intensite(200){
  harderdelay = millis();
}

DifficultyManager::~DifficultyManager(){

}

void DifficultyManager::resetspawn(){
  spawndelaymode1 = 4000;
  intensite = 200;
}

void DifficultyManager::harder(){
  if (((millis() - harderdelay) > 500) && (intensite > 120)) {
    intensite -= 1;
    harderdelay = millis();
  }
  else if (((millis() - harderdelay) > 500) && (spawndelaymode1 > 800)) {
    spawndelaymode1 -= 100;
    harderdelay = millis();
  }
}

int DifficultyManager::getspawndelaymode1(){
  return spawndelaymode1;
}

int DifficultyManager::getspawndelaymode2(){
  return spawndelaymode2;
}

int DifficultyManager::getintensite(){
  return intensite;
}
#include "LCD.h"
#include <Wire.h> // Pour la communication I2C

LCD::LCD(String name):Actuators(name){}

LCD::LCD(String name, int x, int y, int z):Actuators(name),r(x), g(y), b(z){}

LCD::~LCD(){

}

void LCD::initialisation(){
  //Wire.begin(4, 5);
  screen.begin(16,2);
  screen.setRGB(r, g, b);
  screen.print("Dino Run...");
  Serial.print("Initialisation de l'écran : ");
  Serial.println(getnom());
}

void LCD::update(){
  screen.setRGB(r,g,b);
}

void LCD::setcouleur(int r, int g, int b){
  this->r = r;
  this->g = g;
  this->b = b;
}

int LCD::getr() {return r;}
int LCD::getb() {return b;}
int LCD::getg() {return g;}
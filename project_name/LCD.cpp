#include "LCD.h"
#include <Wire.h> // Pour la communication I2C

LCD::LCD(String name, uint8_t pin):Actuators(name, pin){}

LCD::LCD(String name, uint8_t pin, int x, int y, int z):Actuators(name, pin),r(x), g(y), b(z){}

LCD::~LCD(){

}

void LCD::initialisation(){
  //Wire.begin(4, 5);
  screen.begin(16,2);
  screen.setRGB(r, g, b);
  screen.print("Dino runner...");
  Serial.print("Initialisation de l'écran : ");
  Serial.println(nom);
}

void LCD::start(){
  screen.clear();
  screen.setCursor(0,0);
  screen.print("Debut dans ");
  screen.setCursor(0,1);
  screen.print("3");
  delay(330);
  screen.print(".");
  delay(330);
  screen.print(".");
  delay(340);
  screen.print("2");
  delay(330);
  screen.print(".");
  delay(330);
  screen.print(".");
  delay(340);
  screen.print("1");
  delay(330);
  screen.print(".");
  delay(330);
  screen.print(".");
  delay(340);
  screen.print("GO!");
  screen.clear();
}

void LCD::update(){
  screen.setRGB(r,g,b);
  for (int i = 0; i < 2; i++){
    for (int j = 0; i < 16; i++){
      screen.setCursor(i,j);

    }
  }
}

void LCD::setcouleur(int r, int g, int b){
  this->r = r;
  this->g = g;
  this->b = b;
}

int LCD::getr() {return r;}
int LCD::getb() {return b;}
int LCD::getg() {return g;}

void LCD::setmatrice(Game_Object* obj, int x, int y){
  matrice[x][y] = obj;
}
#include "LCD.h"
#include <Wire.h> // Pour la communication I2C

uint8_t dinodino[8] = {
  0b00111, //   ###
  0b00101, //   # #
  0b00111, //   ###
  0b00100, //   #
  0b11110, // ####
  0b01010, //  # #
  0b01010, //  # #
  0b00000
};

LCD::LCD(String name, uint8_t pin):Actuators(name, pin){}

LCD::LCD(String name, uint8_t pin, int x, int y, int z):Actuators(name, pin),r(x), g(y), b(z){}

LCD::~LCD(){

}

void LCD::initialisation(){
  //Wire.begin(4, 5);
  screen.begin(16,2);
  //screen.setRGB(r, g, b);
  //screen.println("Dino runner...");
  //screen.print("Start: press red");
  this->waiting_screen();
  Serial.print("Initialisation de l'écran : ");
  Serial.println(nom);
  screen.createChar(0, dinodino); //créé les dessins de nos objets dans la mémoire associée au lcd
}

void LCD::waiting_screen(){
  screen.clear();
  this->setcouleur(255, 255, 255);
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 16; j++){
      this->setmatrice(nullptr, i, j);
    }
  }
  screen.setCursor(0,0);
  screen.setRGB(r, g, b);
  screen.print("Dino runner...");
  screen.setCursor(0,1);
  screen.print("Start: press red");
}

void LCD::start(){
  screen.clear();
  screen.setCursor(0,0);
  screen.print("Debut dans : ");
  screen.setCursor(0,1);
  screen.print("3");
  delay(250);
  screen.print(".");
  delay(250);
  screen.print(".");
  delay(250);
  screen.print(".");
  delay(250);
  screen.print("2");
  delay(250);
  screen.print(".");
  delay(250);
  screen.print(".");
  delay(250);
  screen.print(".");
  delay(250);
  screen.print("1");
  delay(250);
  screen.print(".");
  delay(250);
  screen.print(".");
  delay(250);
  screen.print(".");
  delay(250);
  screen.print("GO!");
  delay(500);
  screen.clear();
}

void LCD::update(){
  screen.setRGB(r,g,b);
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 16; j++){
      screen.setCursor(j,i);
      if (matrice[i][j] != nullptr){
        if (matrice[i][j]->getshape() == dinodino)
        screen.write((uint8_t)0);
      }
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
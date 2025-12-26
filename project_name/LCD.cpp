#include <sys/types.h>
#include <stdint.h>
#include "LCD.h"
#include <Wire.h> // Pour la communication I2C

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

uint8_t dinodinolying[8] = {
  0b00000,
  0b00000, //
  0b00000, //
  0b00000, //
  0b00000, //
  0b11111, // #####
  0b10101, // # # #
  0b10111 //  # ###
};

uint8_t cactus[8] = {
  0b00100, //   #
  0b00100, //   #
  0b01100, //  ##
  0b11101, // ### #
  0b11111, // #####
  0b00100, //   #
  0b00100, //   #
  0b00100 //   #
};

uint8_t cactus_mid_left[8] = {
  0b10000, // #
  0b10000, // #
  0b10000, // #
  0b10100, // # #
  0b11100, // ###
  0b10000, // #
  0b10000, // #
  0b10000 //  #
};

uint8_t cactus_mid_right[8] = {
  0b00001, //     #
  0b00001, //     #
  0b00011, //    ##
  0b00111, //   ###
  0b00111, //   ###
  0b00001, //     #
  0b00001, //     #
  0b00001 //      #
};

uint8_t bird[8] = {
  0b00100, //   #
  0b00100, //   #
  0b10100, // # #
  0b11111, // #####
  0b01110, //  ###
  0b00000, //
  0b00000, //
  0b00000 //
};

uint8_t bird_mid_left[8] = {
  0b10000,
  0b10000,
  0b10000,
  0b11100,
  0b11000,
  0b00000,
  0b00000,
  0b00000
};

uint8_t bird_mid_right[8] = {
  0b00001,
  0b00001,
  0b00101,
  0b00111,
  0b00011,
  0b00000,
  0b00000,
  0b00000
};

LCD::LCD(String name, uint8_t pin):Actuators(name, pin){}

LCD::LCD(String name, uint8_t pin, int x, int y, int z):Actuators(name, pin),r(x), g(y), b(z){
  currentmode = MENU;
}

LCD::~LCD(){

}

void LCD::initialisation(){
  //Wire.begin(4, 5);
  screen.begin(16,2);
  this->waiting_screen();
  Serial.print("Initialisation de l'écran : ");
  Serial.println(nom);
  screen.createChar(0, dinodino); //créé les dessins de nos objets dans la mémoire associée au lcd
  screen.createChar(1, cactus);
  screen.createChar(2, bird);
  screen.createChar(3, dinodinolying);
  screen.createChar(4, cactus_mid_left);
  screen.createChar(5, cactus_mid_right);
  screen.createChar(6, bird_mid_left);
  screen.createChar(7, bird_mid_right);
}

void LCD::waiting_screen(){
  screen.clear();
  ligne0 = "Dino runner...";
  ligne1 = "Start: press red";
  this->setcouleur(255, 255, 255);
  this->resetmatrice();
  screen.setCursor(0,0);
  screen.setRGB(r, g, b);
  screen.print(ligne0);
  screen.setCursor(0,1);
  screen.print(ligne1);
  currentmode = MENU;
}

void LCD::ending_screen(){
  screen.clear();
  ligne0 = "GAME OVER !!";
  ligne1 = "press orange";
  this->setcouleur(255, 0, 0);
  this->resetmatrice();
  screen.setCursor(0,0);
  screen.setRGB(r, g, b);
  screen.print(ligne0);
  screen.setCursor(0,1);
  screen.print(ligne1);
  currentmode = OVER;
}

void LCD::start(){
  screen.clear();
  screen.setCursor(0,0);
  ligne0 = "Debut dans : ";
  screen.print(ligne0);
  screen.setCursor(0,1);
  ligne1 = "3...2...1...GO!";
  for (int i = 0; i < 12; i++) {
    screen.print(ligne1[i]);
    delay(250);
  }
  screen.print(ligne1[12]);
  screen.print(ligne1[13]);
  screen.print(ligne1[14]);
  delay(500);
  screen.clear();
  currentmode = JEU;
}

void LCD::update(){
  if (currentmode == MENU || currentmode == OVER){

  }
  else {
    screen.setRGB(r,g,b);
    for (int i = 0; i < 2; i++){
      for (int j = 0; j < 16; j++){
        screen.setCursor(j,i);
        if (matrice[i][j] != nullptr){
          if (matrice[i][j]->getshape() == dinodino){
            screen.write((uint8_t)0);
          }
          else if (matrice[i][j]->getshape() == cactus) {
            screen.write((uint8_t)1);
          }
          else if (matrice[i][j]->getshape() == bird) {
            screen.write((uint8_t)2);
          }
          else if (matrice[i][j]->getshape() == dinodinolying) {
            screen.write((uint8_t)3);
          }
          else if (matrice[i][j]->getshape() == cactus_mid_left) {
            screen.write((uint8_t)4);
          }
          else if (matrice[i][j]->getshape() == cactus_mid_right){
            screen.write((uint8_t)5);
          }
          else if (matrice[i][j]->getshape() == bird_mid_left) {
            screen.write((uint8_t)6);
          }
          else if (matrice[i][j]->getshape() == bird_mid_right) {
            screen.write((uint8_t)7);
          }
        }
        else { // Gestion pour ne pas efface la case dans le cas ou il y a la partie droite "fantome" à mettre
          bool skipprintnull = false;
          if (matrice[i][j-1] != nullptr && j > 0){
            if (matrice[i][j-1]->getshape() == cactus_mid_left){
              skipprintnull = true;
              screen.write((uint8_t)5);
            }
            else if (matrice[i][j-1]->getshape() == bird_mid_left){
              skipprintnull = true;
              screen.write((uint8_t)7);
            }
          }
          if (!skipprintnull) screen.print(" ");
        }
      }
    }
  }
}

void LCD::resetmatrice(){
  for (int i = 0; i < 2; i++){
      for (int j = 0; j < 16; j++){
        this->setmatrice(nullptr, i, j);
      }
  }
}

bool LCD::collision(Game_Object* obj1, Game_Object* obj2){
  bool samecase = obj1->getx() == obj2->getx() && obj1->gety() == obj2->gety();
  bool samebit = false;
  for (int i = 0; i < 8; i++) {
    samebit |= obj1->getshape()[i] & obj2->getshape()[i];
  }
  if (obj1->getshape() == dinodinolying || obj1->getshape() == dinodino) return (samecase && samebit);
  return false;
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
  if (y >= 0) matrice[x][y] = obj;
}
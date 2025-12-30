#include "c_types.h"
#include <stdint.h>
#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <Arduino.h>

class Game_Object{
  protected:
    uint8_t* full_shape; // Forme d' l'objet (8 objets maximum)
    int x; //Ligne sur le lcd
    int y; //Colonne sur le lcd
    uint8_t* currentshape;
  public:
    Game_Object(uint8_t* tab, int x, int y);
    ~Game_Object();
    void setpos(int x, int y);
    int getx();
    int gety();
    uint8_t* getshape(); //getteur de la forme de l'objet
    void changeshape(uint8_t* tab);
    virtual void update_pos()= 0;
};

#endif
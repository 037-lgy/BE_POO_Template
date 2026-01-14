#include "c_types.h"
#include <stdint.h>
#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <Arduino.h>

extern uint8_t dark[8];

class Game_Object{
  protected:
    uint8_t* full_shape; // Forme d' l'objet (8 objets maximum)
    int x; //Ligne sur le lcd
    int y; //Colonne sur le lcd
    uint8_t* currentshape;
  public:
    /**
     *@fn Game_Object(uint8_t* tab, int x, int y)
     *@brief Constructeur de la classe Game_Object
     *@param tab forme à donner à notre objet
     *@param x Ligne du lcd sur laquelle l'objet est présent à sa construction
     *@param y Colonne du lcd sur laquelle l'objet est présent à sa construction
    */
    Game_Object(uint8_t* tab, int x, int y);

    /**
     *@fn ~Game_Object()
     *@brief Destructeur de la classe Game_Object
    */
    ~Game_Object();

    /**
     *@fn void setpos(int x, int y)
     *@brief Modifie la position de notre objet sur le lcd
     *@param x Ligne du lcd sur laquelle l'objet est positionné
     *@param y Colonne du lcd sur laquelle l'objet est positionné
    */
    void setpos(int x, int y);

    /**
     *@fn int getx()
     *@brief Retourne la valeur de notre variable x
     *@return int x
    */
    int getx();

    /**
     *@fn int gety()
     *@brief Retourne la valeur de notre variable y
     *@return int y
    */
    int gety();

    /**
     *@fn uint8_t* getshape()
     *@brief Retourne la forme de notre objet
     *@return uint8_t* full_shape
    */
    uint8_t* getshape();

    /**
     *@fn void changeshape(uint8_t* tab)
     *@brief Change la forme de notre objet
     *@param tab nouvelle forme de notre objet
    */
    void changeshape(uint8_t* tab);

    /**
     *@fn virtual void update_pos_basic(int intensity = -1)= 0
     *@brief Update la position de notre objet dans le lcd
     *@param intensity égale à -1 par défaut, pour gérer la vitesse de déplacement dans le temps
     *@details doit être définie par les classes filles 
    */
    virtual void update_pos_basic(int intensity = -1)= 0;

    /**
     *@fn virtual void reset(int x, int y)= 0
     *@brief reset la position de l'objet dans le lcd
     *@param x Ligne du lcd sur laquelle l'objet est positionné
     *@param y Colonne du lcd sur laquelle l'objet est positionné
     *@details doit être définie par les classes filles
    */
    virtual void reset(int x, int y)= 0;
};

#endif
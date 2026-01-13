#ifndef DINO_H_
#define DINO_H_

#include "Game_Object.h"
#include <Arduino.h>

class Dino : public Game_Object{
  private:
    bool isjumping;
    bool islanding;
    unsigned long jumptime;
    unsigned long landtime;
  public :
    /**
     *@fn Dino(uint8_t* tab, int x, int y)
     *@brief Constructeur de la classe Dino
     *@param tab forme à donner à notre Dino
     *@param x Ligne du lcd sur laquelle l'objet est présent à sa construction
     *@param y Colonne du lcd sur laquelle l'objet est présent à sa construction
    */
    Dino(uint8_t* tab, int x, int y);

    /**
     *@fn ~Dino()
     *@brief Destructeur de la classe Dino
    */
    ~Dino();

    /**
     *@fn void jump()
     *@brief gestion du saut de notre dinosaur
    */
    void jump();

    /**
     *@fn void update_pos_basic(int Intensity = -1)
     *@brief update la position de notre dinausor sur le lcd
     *@param Intensity égale à -1 par défaut, non utilisé ici
    */
    void update_pos_basic(int Intensity = -1);

    /**
     *@fn bool getisjumping()
     *@brief retourne la valeur de la variable isjumping pour savoir si on est en train de sauter
    */
    bool getisjumping();

    /**
     *@fn void reset(int x, int y)
     *@brief reset la position du dino dans le lcd
     *@param x Ligne du lcd sur laquelle le dino est reset
     *@param y Colonne du lcd sur laquelle le dino est reset
    */
    void reset(int x, int y);
};

#endif
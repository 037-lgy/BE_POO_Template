#include <stdint.h>
#ifndef ENEMY_OBJECTS
#define ENEMY_OBJECTS

#include "Game_object.h"

class Enemy_objects : public Game_Object{
  protected:
    bool isgoingleft;
    unsigned long gotime;
  public:
    /**
     *@fn Enemy_objects(uint8_t* tab, int x, int y)
     *@brief Constructeur de la classe Enemy_objects
     *@param tab forme à donner à notre Enemy_objects
     *@param x Ligne du lcd sur laquelle l'objet est présent à sa construction
     *@param y Colonne du lcd sur laquelle l'objet est présent à sa construction
    */
    Enemy_objects(uint8_t* tab, int x, int y);

    /**
     *@fn ~Enemy_objects()
     *@brief Destructeur de la classe Enemy_objects
    */
    ~Enemy_objects();

    /**
     *@fn void update_pos_basic(int Intensity = -1)
     *@brief update la position de notre objet ennemi sur le lcd
     *@param Intensity égale à -1 par défaut, utilisé ici pour augmenter la difficulté au cours du temps en augmentant la vitesse du l'objet sur le lcd
    */
    void update_pos_basic(int Intensity = -1);

    /**
     *@fn void spawn(int x, int y);
     *@brief fait spawn l'objet à la position (x,y) du lcd
     *@param x la ligne sur laquelle l'objet spawn
     *@param y la colonne sur laquelle l'objet spawn, par défaut à 15
    */
    void spawn(int x, int y = 15);

    /**
     *@fn virtual void reset()= 0
     *@brief reset la position de l'objet dans le lcd
     *@details doit être définie par les classes filles
    */
    virtual void reset()= 0;
};

#endif
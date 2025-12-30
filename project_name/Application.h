/*********************************************************************
 * @file  Apllication.h
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier header de l'application
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <iostream>
#include <list>
#include "LCD.h"
#include "LED.h"
#include "Buzzer.h"
#include "Button.h"
#include "Potentiometre.h"
#include "Dino.h"
#include "Enemy_objects.h"

using namespace std;

enum state{EN_ATTENTE, EN_JEU, GAME_OVER};

/**
  * @class Application
  * @brief Classe Application   
*/    
class Application
{
  private :
    LCD* my_screen;
    LED* led1;
    LED* led2;
    LED* led3;
    Buzzer* buzzer;
    list<Actuators *> my_actuators;

    Button* button_rouge;
    Button* button_orange;
    Potentiometre* potentiometre;
    list<Sensors *> my_sensors;

    state currentstate;
    state previousstate; //Pour éviter de réafficher en boucle le même texte

    Dino* my_dino;
    Enemy_objects* cactus1;
    Enemy_objects* cactus2;
    Enemy_objects* bird1;
    Enemy_objects* bird2;
    list<Game_Object *> my_objects;
    unsigned long lastspawn;
    int spawndelay;
  public :
    /**
     * @fn Application();
     * @brief Constructeur par defaut
    */    
    Application();
    /**
     * @fn Application();
     * @brief Destructeur
    */    
    ~Application();    
    /**
     * @fn void init(void)
     * @brief Fonction d'initialisation de l'application
    */
    void init(void);
    /**
     * @fn void run(void)
     * @brief Fonction de lancement de l'application
    */
    void run(void);
    /**
    */
    void randomspawn();
};
#endif
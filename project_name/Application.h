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
#include "Cactus.h"
#include "Bird.h"
#include "Powerup.h"
#include "score.h"

using namespace std;

enum state{EN_ATTENTE, EN_JEU, NEW_MODE, GAME_OVER};

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
    Cactus* cactus1;
    Cactus* cactus2;
    Cactus* cactus3;
    Bird* bird1;
    Bird* bird2;
    Bird* bird3;
    Power_up* my_powerup;
    list<Game_Object *> my_objects;

    Score* my_score;

    unsigned long lastspawn;
    int spawndelay;
    int spawndelayMODE2;
    int decompte;
    unsigned long starttime;
    unsigned long lastime;
    unsigned long darkrefreshing;
    unsigned long tempsdecompte;
    int intensite;
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
    void randomspawn_mode1();
    void randomspawn_mode2();

    bool detectercollision();
    void updatescore();
};
#endif
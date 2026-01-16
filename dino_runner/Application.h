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
#include "DifficultyManager.h"

using namespace std;

enum state { EN_ATTENTE,
             EN_JEU,
             NEW_MODE,
             GAME_OVER };

/**
  * @class Application
  * @brief Classe Application   
*/
class Application {
private:
  LCD* my_screen;
  LED* led1;
  LED* led2;
  LED* led3;
  Buzzer* buzzer;
  list<Actuators*> my_actuators;

  Button* button_rouge;
  Button* button_orange;
  Potentiometre* potentiometre;
  list<Sensors*> my_sensors;

  state currentstate;
  state previousstate;

  Dino* my_dino;
  Cactus* cactus1;
  Cactus* cactus2;
  Cactus* cactus3;
  Bird* bird1;
  Bird* bird2;
  Bird* bird3;
  Power_up* my_powerup;
  list<Game_Object*> my_objects;

  Score my_score;
  DifficultyManager my_diffmanager;

  unsigned long lastspawn;
  int decompte;
  unsigned long starttime;
  unsigned long darkrefreshing;
  unsigned long tempsdecompte;

public:
  /**
     * @fn Application();
     * @brief Constructeur de notre application
    */
  Application();
  /**
     * @fn ~Application();
     * @brief Destructeur de notre application
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
     *@fn void randomspawn_mode1()
     *@brief Gestion du spawn pour le mode de jeu normal
    */
  void randomspawn_mode1();

  /**
     *@fn void randomspawn_mode2()
     *@brief Gestion du spawn pour le second mode de jeu
    */
  void randomspawn_mode2();

  /**
     *@fn bool detectercollision()
     *@brief Automatisation de la gestion des collisions du dino avec tous les objets ennemis
    */
  bool detectercollision();

  /**
     *@fn void ColorManager()
     *@brief Gestion de la couleur de l'écran de jeu avec le potentiomètre
  */
  void ColorManager();
};
#endif
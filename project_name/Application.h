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

using namespace std;

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
    list<Actuators *> my_actuators;
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
};
#endif
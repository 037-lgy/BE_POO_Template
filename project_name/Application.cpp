/*********************************************************************
 * @file  Apllication.cpp
 * @author Léo Legay / William Woodward
 * @brief Fichier source de l'application
 *********************************************************************/
#include <iostream>
#include <list>
#include "Application.h"
#include "LCD.h"

using namespace std;

Application::Application()
{
  my_screen = new LCD("Ecran de jeu", 0, 0, 0);
  my_actuators.push_back(my_screen);
}
  
Application::~Application()
{
  // Code
  ;
}  

void Application::init(void)
{
  Serial.begin(115200);
  for (Actuators* actuator : my_actuators) actuator->initialisation();
}


void Application::run(void)
{
  Serial.println(my_screen->getr());
  my_screen->setcouleur(my_screen->getr()+50, my_screen->getg()+40, my_screen->getb()+30);
  for (Actuators* actuator : my_actuators) actuator->update();
  delay(4000);
}

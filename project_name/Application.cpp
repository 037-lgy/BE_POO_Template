#include <Arduino.h>
#include "pins_arduino.h"
#include <iostream>
#include <list>
#include "Application.h"

using namespace std;

/*********************************************************************
 * @file  Apllication.cpp
 * @author Léo Legay / William Woodward
 * @brief Fichier source de l'application
 *********************************************************************/


Application::Application()
{
  my_screen = new LCD("Ecran de jeu", 1, 0, 0, 0);
  led1 = new LED("led_bouton1", D5);
  led2 = new LED("led_bouton2", D0);
  led3 = new LED("led_simple", D7);
  buzzer = new Buzzer("Buzzer", D4); //A voir sur quel port le mettre ? D4 pourrait fonctionner mais après le téléversement
  my_actuators.push_back(my_screen);
  my_actuators.push_back(led1);
  my_actuators.push_back(led2);
  my_actuators.push_back(led3);
  my_actuators.push_back(buzzer);

  button_rouge = new Button("Bouton rouge", D6);
  button_orange = new Button("Bouton orange", D3);
  potentiometre = new Potentiometre("Potentiometre", A0);
  my_sensors.push_back(button_rouge);
  my_sensors.push_back(button_orange);
  my_sensors.push_back(potentiometre);

  currentstate = EN_ATTENTE;
  previousstate = EN_JEU;

  my_dino = new Dino(dinodino, 0, 4);
  my_objects.push_back(my_dino);
}
  
Application::~Application()
{
  // Code
  ;
}  

void Application::init(void)
{
  Serial.begin(9600);
  delay(500); //Pour stabiliser les courants sur la carte
  Serial.println("--DEBUT DE L'INITIALISATION--");
  for (Actuators* actuator : my_actuators) {
    actuator->initialisation();
    delay(100);
  }
  for (Sensors* sensor : my_sensors) {
    sensor->initialisation();
    delay(100);
  }
  Serial.println("--FIN DE L'INITIALISATION--");
}


void Application::run(void)
{
  if (currentstate == EN_ATTENTE){
    if (button_rouge->readsensor() == LOW){
      my_screen->start();
      currentstate = EN_JEU;
    }
    else if (previousstate != EN_ATTENTE){
      my_screen->waiting_screen();
      previousstate = EN_ATTENTE;
    }
  }
  else if (currentstate == EN_JEU) {
    if(button_orange->readsensor() == LOW){
      currentstate = EN_ATTENTE;
    }
    else {
      my_screen->setcouleur(0, 0, 0);
      my_screen->setmatrice(my_dino, my_dino->getx(), my_dino->gety());
      previousstate = EN_JEU;
    }
  }
  for (Actuators* actuator : my_actuators) actuator->update();
}

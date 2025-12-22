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
  my_screen = new LCD("Ecran de jeu", 4, 0, 0, 0);
  led1 = new LED("led_bouton1", D5);
  led2 = new LED("led_bouton2", D0);
  led3 = new LED("led_simple", D7);
  buzzer = new Buzzer("Buzzer", D4); //A voir sur quel port le mettre ? D4 pourrait fonctionner mais après le téléversement
  my_actuators.push_back(my_screen);
  my_actuators.push_back(led1);
  my_actuators.push_back(led2);
  my_actuators.push_back(led3);
  my_actuators.push_back(buzzer);

  button1 = new Button("Bouton1", D6);
  button2 = new Button("Bouton2", D3);
  potentiometre = new Potentiometre("Potentiometre", A0);
  my_sensors.push_back(button1);
  my_sensors.push_back(button2);
  my_sensors.push_back(potentiometre);
}
  
Application::~Application()
{
  // Code
  ;
}  

void Application::init(void)
{
  Serial.begin(9600);
  delay(500); //Pour stabiliser les courants se stabiliser sur la carte
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
  while(button1->readsensor() == HIGH){}
  my_screen->start();
}


void Application::run(void)
{
  // if (button1->readsensor() == HIGH || button2->readsensor() == HIGH) {
  //   led1->set_off();
  //   led2->set_off();
  //   led3->set_off();
  //   buzzer->set_off();
  // }
  // else {
  //   led1->set_on();
  //   led2->set_on();
  //   led3->set_on();
  //   buzzer->set_on();
  //   my_screen->setcouleur(my_screen->getr()+30,my_screen->getg()+20,my_screen->getb()+50);
  //   Serial.println(potentiometre->readsensor());
  // }
  //if (button1->readsensor() == LOW) my_screen->start();
  for (Actuators* actuator : my_actuators) actuator->update();
}

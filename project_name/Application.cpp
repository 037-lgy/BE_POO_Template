#include <Arduino.h>
#include "pins_arduino.h"
#include <iostream>
#include <list>
#include "Application.h"
#include "LCD.h"
#include "LED.h"
#include "Buzzer.h"
#include "Button.h"
#include "Potentiometre.h"

using namespace std;

/*********************************************************************
 * @file  Apllication.cpp
 * @author Léo Legay / William Woodward
 * @brief Fichier source de l'application
 *********************************************************************/


Application::Application()
{
  my_screen = new LCD("Ecran de jeu", 4, 0, 0, 0);
  led1 = new LED("led_bouton1",D5);
  led2 = new LED("led_bouton2", D0);
  led3 = new LED("led_simple",D7);
  my_actuators.push_back(my_screen);
  my_actuators.push_back(led1);
  my_actuators.push_back(led2);
  my_actuators.push_back(led3);
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
  int bouton1 = digitalRead(D6);
  //int bouton2 = digitalRead(D8);
  if (bouton1 == HIGH ) {//|| bouton2 == HIGH
    led1->set_off();
    led2->set_off();
    led3->set_off();
    //digitalWrite(D9, LOW);  // SIG reçoit 3.3V -> La LED s'éteint
  }
  else {
    led1->set_on();
    led2->set_on();
    led3->set_on();
    //digitalWrite(D9, HIGH);   // SIG reçoit 0V -> La LED s'allume
    my_screen->setcouleur(my_screen->getr()+30,my_screen->getg()+20,my_screen->getb()+50);
  }
  for (Actuators* actuator : my_actuators) actuator->update();
}

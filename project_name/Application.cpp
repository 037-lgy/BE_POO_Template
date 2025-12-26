#include "core_esp8266_features.h"
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

  my_dino = new Dino(dinodino, 1, 4);
  //cactus1 = new Cactus(cactus, 1, 15);
  //bird1 = new Bird(bird, 0, -10);
  //cactus2 = new Cactus(cactus, 1, -10);
  //bird2 = new Bird(bird, 0, -10);
  cactus1 = new Enemy_objects(cactus, cactus_mid_left, cactus_mid_right, 1, 15);
  cactus2 = new Enemy_objects(cactus, cactus_mid_left, cactus_mid_right, 1, -10);
  bird1 = new Enemy_objects(bird, bird_mid_left, bird_mid_right, 0, -10);
  bird2 = new Enemy_objects(bird, bird_mid_left, bird_mid_right, 1, -10);
  my_objects.push_back(my_dino);
  my_objects.push_back(cactus1);
  my_objects.push_back(bird1);
  my_objects.push_back(cactus2);
  my_objects.push_back(bird2);

  spawndelay = 3000;
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
  lastspawn = (unsigned long)0;
}

void Application::randomspawn(){
  if ((millis() - lastspawn) >= spawndelay){
    int choice = random(3);
    if (choice == 0){
      if (cactus1->gety() <= -1){
        cactus1->spawn(1);
      }
      else if (cactus2->gety() <= -1) {
        cactus2->spawn(1);
      }
    }
    else if (choice == 1){
      if (bird1->gety() <= -1){
        bird1->spawn(0);
      }
      else if (bird2->gety() <= -1) {
        bird2->spawn(0);
      }
    }
    else if (choice == 2){
      if (bird1->gety() <= -1){
        bird1->spawn(1);
      }
      else if (bird2->gety() <= -1) {
        bird2->spawn(1);
      }
    }
    lastspawn = millis();
    // Il faudra changer le delay de spawn suivant soit l'avancement dans le jeu, soit le potentiomètre
  }
}

void Application::run(void) {
  if (currentstate == EN_ATTENTE){
    if (button_rouge->readsensor() == LOW){
      my_screen->start();
      currentstate = EN_JEU;
    }
    else if (previousstate != EN_ATTENTE){
      my_screen->waiting_screen();
      my_dino->changeshape(dinodino);
      led2->set_off();
      led1->set_on();
      my_dino->setpos(1, 4);
      cactus1->setpos(1, 15);
      bird1->setpos(0, -10);
      cactus2->setpos(1, -10);
      bird2->setpos(1, -10);
      previousstate = EN_ATTENTE;
    }
  }
  else if (currentstate == EN_JEU) {
    led1->set_off();
    randomspawn();
    if(my_screen->collision(my_dino, cactus1) || 
    my_screen->collision(my_dino, bird1) || 
    my_screen->collision(my_dino, cactus2) || 
    my_screen->collision(my_dino, bird2)){
      currentstate = GAME_OVER;
    }
    else {
      if (button_orange->readsensor() == LOW && button_rouge->readsensor() == HIGH){
        my_dino->changeshape(dinodinolying);
      }
      else {
        my_dino->changeshape(dinodino);
      }
      if (button_rouge->readsensor() == LOW && !(my_dino->getisjumping()) && button_orange->readsensor() == HIGH){
        my_dino->jump();
      }
      my_screen->setcouleur(120, 120, 120);
      my_screen->resetmatrice();
      my_dino->update_jump();
      cactus1->update_pos();
      bird1->update_pos();
      cactus2->update_pos();
      bird2->update_pos();
      for (Game_Object* objects : my_objects) my_screen->setmatrice(objects, objects->getx(), objects->gety());
      previousstate = EN_JEU;
    }
  }
  else if (currentstate == GAME_OVER) {
    led2->set_on();
    delay(200);
    if (button_orange->readsensor() == LOW){
      delay(200);
      currentstate = EN_ATTENTE;
    }
    else if (previousstate != GAME_OVER){
      my_screen->ending_screen();
      // on peut allumer / faire clignoter des leds
      previousstate = GAME_OVER;
    }
  }
  for (Actuators* actuator : my_actuators) {
    actuator->update();
  }
}
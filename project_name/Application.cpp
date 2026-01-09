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
  buzzer = new Buzzer("Buzzer", D9); //A voir sur quel port le mettre ? D4 pourrait fonctionner mais après le téléversement
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

  cactus1 = new Enemy_objects(cactus, 1, -1);
  cactus2 = new Enemy_objects(cactus, 1, -1);
  bird1 = new Enemy_objects(bird, 0, -1);
  bird2 = new Enemy_objects(bird, 1, -1);
  my_powerup = new Enemy_objects(powerup, 0, -1);

  my_objects.push_back(my_dino);
  my_objects.push_back(cactus1);
  my_objects.push_back(bird1);
  my_objects.push_back(cactus2);
  my_objects.push_back(bird2);
  my_objects.push_back(my_powerup);

  spawndelay = 4000;
  spawndelayMODE2 = 800;
  lastime = 0;
  score = 0;
  scorerefreshing = 0;
  intensite = 200;
  darkrefreshing = 0;
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
  Serial.print("Nombre de devices : ");
  Serial.println(potentiometre->getnbdevices());
  Serial.println("--FIN DE L'INITIALISATION--");
  lastspawn = (unsigned long)0;
}

void Application::randomspawn_mode1(){
  if ((millis() - lastspawn) >= spawndelay){
    int choice = random(4);
    if (choice == 0){
      if (cactus1->gety() == -1){
        cactus1->spawn(1);
      }
      else if (cactus2->gety() == -1) {
        cactus2->spawn(1);
      }
    }
    else if (choice == 1){
      if (bird1->gety() == -1){
        bird1->spawn(0);
      }
      else if (bird2->gety() == -1) {
        bird2->spawn(0);
      }
    }
    else if (choice == 2){
      if (bird1->gety() == -1){
        bird1->spawn(1);
      }
      else if (bird2->gety() == -1) {
        bird2->spawn(1);
      }
    }
    else if (choice == 3) {
      if (my_powerup->gety() == -1){
        my_powerup->spawn(0);
      }
    }
    lastspawn = millis();
  }
}

void Application::randomspawn_mode2(){
  if ((millis() - lastspawn) >= spawndelayMODE2){
    int choice = random(3);
    if (choice == 0){
      if (cactus1->gety() == -1){
        cactus1->spawn(1);
      }
      else if (cactus2->gety() == -1) {
        cactus2->spawn(1);
      }
    }
    else if (choice == 1){
      if (bird1->gety() == -1){
        bird1->spawn(0);
      }
      else if (bird2->gety() == -1) {
        bird2->spawn(0);
      }
    }
    else if (choice == 2){
      if (bird1->gety() == -1){
        bird1->spawn(1);
      }
      else if (bird2->gety() == -1) {
        bird2->spawn(1);
      }
    }
    lastspawn = millis();
  }
}

void Application::updatescore(){
  if (currentstate == EN_JEU) score = score + (millis() - lastime);
  else if (currentstate == NEW_MODE) score = score + 3*(millis() - lastime);
  lastime = millis();
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

      my_dino->reset(1, 4);

      cactus1->reset(1, -1);
      bird1->reset(0, -1);
      cactus2->reset(1, -1);
      bird2->reset(1, -1);
      my_powerup->reset(0, -1);

      my_screen->resetmatrice();

      score = 0;
      lastime = millis();
      lastspawn = millis();
      previousstate = EN_ATTENTE;
    }
  }
  else if (currentstate == EN_JEU) {
    if (previousstate != EN_JEU){
      previousstate = EN_JEU;
      starttime = millis();
      lastime = millis();
      lastspawn = millis();
      darkrefreshing = millis();
      my_screen->setlightmode();
      my_screen->setcouleur(120, 120, 120);
      led1->set_off();
      my_dino->reset(1, 4);
      my_dino->changeshape(dinodino);
    }
    else if (my_screen->collision(my_dino, cactus1) || 
    my_screen->collision(my_dino, bird1) || 
    my_screen->collision(my_dino, cactus2) || 
    my_screen->collision(my_dino, bird2)){
      currentstate = GAME_OVER;
      spawndelay = 4000;
      intensite = 200;
    }
    else if (my_screen->collision(my_dino, my_powerup)) {
      currentstate = NEW_MODE;
    }
    else {
      randomspawn_mode1();
      updatescore();

      if (millis() - darkrefreshing > 40000 && !(millis() - darkrefreshing > 50000)) my_screen->setdarkmode();
      else if (millis() - darkrefreshing > 50000) my_screen->setlightmode();
      //if (millis() - darkrefreshing > 40000) my_screen->setdarkmode();

      // Changements à tester ici 
      if (potentiometre->readsensor() < 256) my_screen->setcouleur(potentiometre->readsensor(), 0, 0);
      else if (potentiometre->readsensor() < 511) my_screen->setcouleur(255, potentiometre->readsensor()-255, 0);
      else my_screen->setcouleur(255, 255, potentiometre->readsensor()-510);
      Serial.println(potentiometre->readsensor());

      if (millis() - scorerefreshing > 500){ 
        my_screen->continuousscore(score);
        scorerefreshing = millis();
        if (intensite > 150) intensite--;
        else if (spawndelay > 1000) spawndelay = spawndelay - 100;
      }
      if (buzzer->getstate() == HIGH) buzzer->set_off(); //Ne pas oublier sinon c'est chiant
      if (button_orange->readsensor() == LOW && button_rouge->readsensor() == HIGH && (!my_dino->getisjumping())){
        my_dino->changeshape(dinodinolyingdown);
      }
      else {
        my_dino->changeshape(dinodino);
      }
      if (button_rouge->readsensor() == LOW && !(my_dino->getisjumping()) && button_orange->readsensor() == HIGH){
        buzzer->set_on();
        my_dino->jump();
      }
      my_screen->resetmatrice();
      for (Game_Object* objects : my_objects) {
        objects->update_pos_basic(intensite);
        my_screen->setmatrice(objects, objects->getx(), objects->gety());
      }
    }
  }
  else if (currentstate == NEW_MODE){
    if (previousstate != NEW_MODE){
      starttime = millis();
      previousstate = NEW_MODE;
      my_dino->changeshape(dinoflip);
      my_dino->reset(0, 4);
    }
    else if ((millis() - starttime) > 500 && (my_screen->collision(my_dino, cactus1) || 
    my_screen->collision(my_dino, bird1) || 
    my_screen->collision(my_dino, cactus2) || 
    my_screen->collision(my_dino, bird2))){
      currentstate = GAME_OVER;
      spawndelay = 4000;
      intensite = 200;
    }
    else {
      randomspawn_mode2();
      updatescore();

      if (millis() - darkrefreshing > 40000 && !(millis() - darkrefreshing > 50000)) my_screen->setdarkmode();
      else if (millis() - darkrefreshing > 50000) my_screen->setlightmode();

      if (potentiometre->readsensor() < 256) my_screen->setcouleur(potentiometre->readsensor(), 0, 0);
      else if (potentiometre->readsensor() < 511) my_screen->setcouleur(255, potentiometre->readsensor()-255, 0);
      else my_screen->setcouleur(255, 255, potentiometre->readsensor()-510);


      if (millis() - scorerefreshing > 500){ 
        my_screen->continuousscore(score);
        scorerefreshing = millis();
      }
      if (button_rouge->readsensor() == LOW && my_dino->getshape() != dinoflip){
        my_dino->changeshape(dinoflip);
        my_dino->setpos(0, my_dino->gety());
      }
      else if (button_orange->readsensor() == LOW  && my_dino->getshape() != dinodino){
        my_dino->changeshape(dinodino);
        my_dino->setpos(1, my_dino->gety());
      }
      my_screen->resetmatrice();
      for (Game_Object* objects : my_objects) {
        my_screen->setmatrice(objects, objects->getx(), objects->gety());
        objects->update_pos_basic(intensite);
      }
      if ((millis() - starttime) > 10000 && (my_screen->getmatrice()[1][4] == nullptr) && (my_screen->getmatrice()[1][5] == nullptr)){
        currentstate = EN_JEU;
      }
    }
  }
  else if (currentstate == GAME_OVER) {
    if (previousstate != GAME_OVER){
      led2->set_on();
      score = score/300;
      my_screen->ending_screen();
      my_screen->desplayscore(score);
      previousstate = GAME_OVER;
      starttime = millis();
    }
    else if (button_orange->readsensor() == LOW && (millis() - starttime) > 1500){
      currentstate = EN_ATTENTE;
    }
    // on peut allumer / faire clignoter des leds
  }
  for (Actuators* actuator : my_actuators) {
    actuator->update();
  }
}
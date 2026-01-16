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
  buzzer = new Buzzer("Buzzer", D8);
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

  cactus1 = new Cactus();
  cactus2 = new Cactus();
  cactus3 = new Cactus();
  bird1 = new Bird();
  bird2 = new Bird();
  bird3 = new Bird();
  my_powerup = new Power_up();

  my_objects.push_back(my_dino);
  my_objects.push_back(cactus1);
  my_objects.push_back(bird1);
  my_objects.push_back(cactus2);
  my_objects.push_back(bird2);
  my_objects.push_back(bird3);
  my_objects.push_back(cactus3);
  my_objects.push_back(my_powerup);

  Score my_score();

  DifficultyManager my_diffmanager();

  lastime = 0;
  darkrefreshing = 0;
}
  
Application::~Application() 
{
  for (Actuators* actuator : my_actuators) {
    delete actuator;
  }

  for (Sensors* sensor : my_sensors) {
    delete sensor;
  }

  for (Game_Object* objects : my_objects) {
    delete objects;
  }
}

void Application::init(void)
{
  Serial.begin(9600);
  delay(500);
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
  if ((millis() - lastspawn) >= my_diffmanager.getspawndelaymode1()){
    int choice = random(5);
    if (choice == 0){
      if (cactus1->gety() == -1){
        cactus1->spawn(1,16);
      }
      else if (cactus2->gety() == -1) {
        cactus2->spawn(1,16);
      }
      else if (cactus3->gety() == -1) {
        cactus3->spawn(1,16);
      }
    }
    else if (choice == 1){
      if (bird1->gety() == -1){
        bird1->spawn(random(2),16);
      }
      else if (bird2->gety() == -1) {
        bird2->spawn(random(2),16);
      }
      else if (bird3->gety() == -1) {
        bird3->spawn(random(2),16);
      }
    }
    else if (choice == 2) {
      if (my_powerup->gety() == -1){
        my_powerup->spawn(0,16);
      }
    }
    else if (choice == 3){
      if (cactus1->gety() == -1 && cactus2->gety() == -1){
        cactus1->spawn(1,16);
        cactus2->spawn(1,15);
      }
      if (cactus2->gety() == -1 && cactus3->gety() == -1){
        cactus2->spawn(1,16);
        cactus3->spawn(1,15);
      }
    }
    else if (choice == 4){
      if (bird1->gety() == -1 && bird2->gety() == -1){
        bird1->spawn(1,16);
        bird2->spawn(0,15);
      }
      if (bird2->gety() == -1 && bird3->gety() == -1){
        bird2->spawn(1,16);
        bird3->spawn(0,15);
      }
    }
    lastspawn = millis();
  }
}

void Application::randomspawn_mode2(){
  if ((millis() - lastspawn) >= my_diffmanager.getspawndelaymode2()){
    int choice = random(2);
    if (choice == 0){
      if (cactus1->gety() == -1){
        cactus1->spawn(1,16);
      }
      else if (cactus2->gety() == -1) {
        cactus2->spawn(1,16);
      }
      else if (cactus3->gety() == -1) {
        cactus3->spawn(1,16);
      }
    }
    else if (choice == 1){
      if (bird1->gety() == -1){
        bird1->spawn(0,16);
      }
      else if (bird2->gety() == -1) {
        bird2->spawn(0,16);
      }
      else if (bird3->gety() == -1) {
        bird3->spawn(0,16);
      }
    }
    lastspawn = millis();
  }
}

bool Application::detectercollision(){
  bool detection;
  for (Game_Object* objects : my_objects) {
        if (objects->getID()==danger){
          detection |= my_screen->collision(my_dino, objects);
      }
  }
      return detection;
}

void Application::ColorManager(){
  float poten;
  poten = potentiometre->readsensor()*0.730476-5.11;
  if ((int) poten < 256) my_screen->setcouleur(0,(int) poten, 0);
  else if ((int) poten < 511) my_screen->setcouleur(255, (int) poten-256, 0);
  else my_screen->setcouleur(255, 255, (int) poten-512);
}

void Application::run(void) {
  float poten;
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

      my_screen->setlightmode();

      for (Game_Object* objects : my_objects) {
        objects->reset();
      }
      my_screen->resetmatrice();

      my_score.resetscore();
      lastspawn = millis();
      previousstate = EN_ATTENTE;
    }
  }
  else if (currentstate == EN_JEU) {
    if (previousstate != EN_JEU){
      starttime = millis();
      my_score.actualiserlastime();
      lastspawn = millis();
      if (previousstate == EN_ATTENTE) darkrefreshing = millis();
      my_screen->setcouleur(120, 120, 120);
      led1->set_off();

      my_dino->reset();

      my_dino->changeshape(dinodino);

      previousstate = EN_JEU;
    }
    else if (detectercollision()){
      currentstate = GAME_OVER;
      my_diffmanager.resetspawn();
    }
    else if (my_screen->collision(my_dino, my_powerup)) {
      currentstate = NEW_MODE;
    }
    else {
      randomspawn_mode1();
      my_score.updatescoreMode1();

      if ((millis() - darkrefreshing) > 15000) {
        darkrefreshing = millis();
        if (my_screen->getdarkmode()) my_screen->setlightmode();
        else my_screen->setdarkmode();
      }

      //Gestion de la couleur du potentiomètre
      ColorManager();

      //affichage du score et actualisation de la difficulté 
      my_screen->continuousscore(my_score.getscore());
      my_diffmanager.harder();
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
        objects->update_pos_basic(my_diffmanager.getintensite());
        my_screen->setmatrice(objects, objects->getx(), objects->gety());
      }
    }
  }
  else if (currentstate == NEW_MODE){
    if (previousstate != NEW_MODE){
      starttime = millis();
      previousstate = NEW_MODE;
      my_dino->changeshape(dinoflip);
    
      my_dino->setpos(0, 4);

      decompte = 9;
      tempsdecompte = millis();
      buzzer->set_off();
    }
    else if (detectercollision()){
      currentstate = GAME_OVER;
      my_diffmanager.resetspawn();
    }
    else {
      if (millis() - starttime < 9000)randomspawn_mode2();
      else randomspawn_mode1();
      
      my_score.updatescoreMode2();

      if ((millis() - darkrefreshing) > 15000) {
        darkrefreshing = millis();
        if (my_screen->getdarkmode()) my_screen->setlightmode();
        else my_screen->setdarkmode();
      }

      ColorManager();

      if (buzzer->getstate() == HIGH) buzzer->set_off(); //Ne pas oublier sinon c'est chiant
      if (millis() - tempsdecompte > 1000){
        my_screen->affichedecompte(decompte);
        decompte--;
        tempsdecompte = millis();
      } 
      if ((millis() - starttime) > 10000 && (my_screen->getmatrice()[1][4] == nullptr) && (my_screen->getmatrice()[1][5] == nullptr)){
        currentstate = EN_JEU;
        my_screen->affichedecompte(0);
      }
      
      my_screen->continuousscore(my_score.getscore());
      if (button_rouge->readsensor() == LOW && my_dino->getshape() != dinoflip){
        my_dino->changeshape(dinoflip);
        my_dino->setpos(0, my_dino->gety());
        buzzer->set_on();
      }
      else if (button_orange->readsensor() == LOW  && my_dino->getshape() != dinodino){
        my_dino->changeshape(dinodino);
        my_dino->setpos(1, my_dino->gety());
        buzzer->set_on();
      }
      my_screen->resetmatrice();
      for (Game_Object* objects : my_objects) {
        my_screen->setmatrice(objects, objects->getx(), objects->gety());
        objects->update_pos_basic(my_diffmanager.getintensite());
      }
    }
  }
  else if (currentstate == GAME_OVER) {
    if (previousstate != GAME_OVER){
      led2->set_on();
      buzzer->set_off();
      my_screen->ending_screen();
      my_score.updatescorefinal();
      my_screen->desplayscore(my_score.getscore(), my_score.gethighscore());
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
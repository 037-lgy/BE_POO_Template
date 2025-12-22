#include <stdint.h>
#include <sys/types.h>
#ifndef LCD_H_
#define LCD_H_

#include "Actuators.h"
#include <rgb_lcd.h>
#include <array>
#include "Game_Object.h"

extern uint8_t dinodino[8];

class LCD : public Actuators{
  private:
    rgb_lcd screen;
    char r,g,b;
    std::array<std::array<Game_Object*, 16>, 2> matrice;
    String ligne0;
    String ligne1;
  public:
    LCD(String name, uint8_t pin);
    LCD(String name, uint8_t pin, int x, int y, int z);
    ~LCD();
    void update();
    void initialisation();
    void waiting_screen();
    void start();
    void setcouleur(int r, int g, int b); //Mettre à jour les couleurs de l'écran
    void setmatrice(Game_Object* obj, int x, int y); //Change la matrice de l'écran lcd
    int getr(); //Récupérer le niveau de rouge
    int getg(); //Récupérer le niveau de vert
    int getb(); //Récupérer le niveau de bleu
};

#endif
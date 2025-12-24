#include <stdint.h>
#include <sys/types.h>
#ifndef LCD_H_
#define LCD_H_

#include "Actuators.h"
#include <rgb_lcd.h>
#include <array>
#include "Game_Object.h"

extern uint8_t dinodino[8];
extern uint8_t cactus[8];
extern uint8_t bird_wings_down[8];
extern uint8_t bird_wings_up[8];

enum mode{MENU, JEU, OVER};

class LCD : public Actuators{
  private:
    rgb_lcd screen;
    char r,g,b;
    std::array<std::array<Game_Object*, 16>, 2> matrice;
    String ligne0;
    String ligne1;
    mode currentmode;
  public:
    LCD(String name, uint8_t pin);
    LCD(String name, uint8_t pin, int x, int y, int z);
    ~LCD();
    void update();
    void initialisation();
    void waiting_screen();
    void ending_screen();
    void start();
    void setcouleur(int r, int g, int b); //Mettre à jour les couleurs de l'écran
    void resetmatrice();
    void setmatrice(Game_Object* obj, int x, int y); //Change la matrice de l'écran lcd
    int getr(); //Récupérer le niveau de rouge
    int getg(); //Récupérer le niveau de vert
    int getb(); //Récupérer le niveau de bleu
};

#endif
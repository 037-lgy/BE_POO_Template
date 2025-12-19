#include <sys/types.h>
#ifndef LCD_H_
#define LCD_H_

#include "Actuators.h"
#include <rgb_lcd.h>

class LCD : public Actuators{
  private:
    rgb_lcd screen;
    char r,g,b;
  public:
    LCD(String name, uint8_t pin);
    LCD(String name, uint8_t pin, int x, int y, int z);
    ~LCD();
    void update();
    void initialisation();
    void setcouleur(int r, int g, int b); //Mettre à jour les couleurs de l'écran
    int getr(); //Récupérer le niveau de rouge
    int getg(); //Récupérer le niveau de vert
    int getb(); //Récupérer le niveau de bleu
};

#endif
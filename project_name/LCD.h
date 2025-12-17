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
    LCD(String name);
    LCD(String name, int x, int y, int z);
    ~LCD();
    void update();
    void initialisation();
    void setcouleur(int r, int g, int b);
    int getr();
    int getg();
    int getb();
};

#endif
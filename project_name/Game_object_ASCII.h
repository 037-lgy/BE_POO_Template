#ifndef GAME_OBJECT_ASCII_H_
#define GAME_OBJECT_ASCII_H_

#include "Enemy_objects.h"

class Game_Object_Ascii : public Enemy_objects{
  private:
    char obj_ascii;
  public:
    Game_Object_Ascii(char obj, int x, int y);
    ~Game_Object_Ascii();
};

#endif
#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <array>

class Game_Object{
  private:
    std::array<std::array<bool, 6>, 8> shape;
    int x;
    int y;
  public:
    Game_Object(std::array<std::array<bool, 6>, 8> tab, int x, int y);
    ~Game_Object();
    void setpos(int x, int y);
};

#endif
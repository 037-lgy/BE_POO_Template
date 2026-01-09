#include "Enemy_objects.h"

Enemy_objects::Enemy_objects(uint8_t* tab, int x, int y):Game_Object(tab, x, y),isgoingleft(false), gotime((unsigned long)0){}

//Enemy_objects::Enemy_objects(uint8_t* shape, uint8_t* left_shape, int x, int y):
//  Game_Object(shape, x, y),left_shape(left_shape), isgoingleft(false), gotime((unsigned long)0), state((int)0){}

// void Enemy_objects::update_pos(){
//   if (y >= 0 ) {
//     if (!isgoingleft){
//       if (state == 0) {
//         currentshape = left_shape;
//       }
//       else if (state == 1) {
//         currentshape = full_shape;
//       }
//       else if (state == 2){
//         currentshape = left_shape;
//       }
//       state++;
//       if (state > 2){
//         state = 0;
//         y--;
//       }
//       isgoingleft = true;
//       gotime = millis();
//     }
//     else if (millis() - gotime >= 50){
//       isgoingleft = false;
//     }
//   }
// }

void Enemy_objects::update_pos_basic(int Intensity){
  if (y >= 0 ) {
    if (!isgoingleft){
      currentshape = full_shape;
      isgoingleft = true;
      gotime = millis();
      y--;
    }
    else if (millis() - gotime >= Intensity){
      isgoingleft = false;
    }
  }
  else {
    isgoingleft = false;
  }
}

void Enemy_objects::spawn(int x, int y = 15){
  this->x = x;
  this->y = y;
  //state = 0;
  isgoingleft = false;
}

void Enemy_objects::reset(int x, int y){
  this->x = x;
  this->y = y;
  isgoingleft = false;
  gotime = 0;
}
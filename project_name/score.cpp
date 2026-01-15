#include "score.h"
#include "core_esp8266_features.h"
#include <Arduino.h>

Score::Score(){
  highestscore = 0;
  score = 0;
  scorerefreshing = 0;
  lastime = 0;
}

void Score::updatescoreMode1(){
  score = score + (millis() - lastime);
  lastime = millis();
}
void Score::updatescoreMode2(){
  score = score + 3*(millis() - lastime);
  lastime = millis();
}

void Score::updatescorefinal(){
  score = score/300;
  if (highestscore < score) highestscore = score;
}

void Score::resetscore(){score = 0;lastime = 0;}

void Score::actualiserlastime(){lastime = millis();}

int Score::getscore(){return score;}

int Score::gethighscore(){return highestscore;}

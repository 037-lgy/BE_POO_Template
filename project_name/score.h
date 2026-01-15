#ifndef SCORE_H_
#define SCORE_H_

class Score {
  private:
  int highestscore;
  int score;
  unsigned long scorerefreshing;
  unsigned lastime;
  public:
  Score();
  void updatescoreMode1();
  void updatescoreMode2();
  void updatescorefinal();
  void resetscore();
  void actualiserlastime();
  int getscore();
  int gethighscore();
};

#endif
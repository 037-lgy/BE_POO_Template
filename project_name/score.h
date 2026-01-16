#ifndef SCORE_H_
#define SCORE_H_

class Score {
  private:
  int highestscore;
  int score;
  unsigned long scorerefreshing;
  unsigned lastime;
  public:

  /**
     *@fn Score()
     *@brief initialise les valeurs de scores et les temps de rafraîchissement
    */
  Score();

  /**
     *@fn updatescoreMode1()
     *@brief met à jour le score dans le mode normal
    */
  void updatescoreMode1();

  /**
     *@fn updatescoreMode2()
     *@brief met à jour le score du mode 2 (le score augmente 3x plus que dans le mode 1)
    */
  void updatescoreMode2();

  /**
     *@fn updatescorefinal()
     *@brief met à jour le score final pour afficher correctement dans le GAMEOVER
    */
  void updatescorefinal();

  /**
     *@fn resetscore()
     *@brief remet à zero le score et met à jour le refraichissement pour relancer une partie
    */
  void resetscore();

  /**
     *@fn actualiserlastime()
     *@brief met à jour le temps de raifraichissement
    */
  void actualiserlastime();

  /**
     *@fn getscore()
     *@brief retourne le score
     *@return renvoie un int
    */
  int getscore();

  /**
     *@fn gethighscore()
     *@brief retourne le score le plus haut (depuis la mise sous tension)
     *@return renvoie un int
    */
  int gethighscore();
};

#endif
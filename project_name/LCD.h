#include <stdint.h>
#include <sys/types.h>
#ifndef LCD_H_
#define LCD_H_

#include "Actuators.h"
#include <rgb_lcd.h>
#include <array>
#include "Dino.h"
#include "Cactus.h"
#include "Bird.h"
#include "Powerup.h"

enum mode{MENU, JEU, OVER};

class LCD : public Actuators{
  private:
    rgb_lcd screen;
    char r,g,b;
    std::array<std::array<Game_Object*, 16>, 2> matrice;
    String ligne0;
    String ligne1;
    mode currentmode;
    bool darkmode;
    unsigned long scorerefreshing;
  public:
    /**
     *@fn LCD(String name, uint8_t pin, int x, int y, int z)
     *@brief Constructeur de la classe LCD
     *@param name nom à donner au LCD
     *@param pin broche du gpio de l'arduino
     *@param x teinte de rouge (valeur de 0 à 255)
     *@param y teinte de vert (valeur de 0 à 255)
     *@param z teinte de bleu (valeur de 0 à 255)
    */
    LCD(String name, uint8_t pin, int x, int y, int z);

    /**
    *@fn ~LCD()
    *@brief destructeur de la classe LCD
    */
    ~LCD();

    /**
    *@fn update()
    *@brief met à jour l'affichage des éléments du jeu sur le LCD en se basant sur la matrice de suivie de position des éléments du jeu
    */
    void update();

    /**
    *@fn initialisation()
    *@brief initialisation de la connexion du module avec le LCD et chargement dans la mémoire du LCD les éléments du jeu
    */
    void initialisation();

    /**
    *@fn waiting_screen()
    *@brief écran d'affichage lorsque l'utilisateur est dans le menu
    */
    void waiting_screen();

    /**
    *@fn ending_screen()
    *@brief écran d'affichage lorsque l'utilisateur vient de perdre une game
    */
    void ending_screen();

    /**
    *@fn start()
    *@brief écran d'affichage pre-jeu lorsque l'utilisateur vient de lancer une game (affichage d'un décompte)
    */
    void start();

    /**
    *@fn setcouleur(int r, int g, int b)
    *@brief Met à jour les couleurs de l'écran
    *@param r teinte de rouge (valeur de 0 à 255)
    *@param g teinte de vert (valeur de 0 à 255)
    *@param b teinte de bleu (valeur de 0 à 255)
    */
    void setcouleur(int r, int g, int b);

    /**
    *@fn resetmatrice()
    *@brief Efface la totalité des éléments du jeu présentsc dans la matrice de suivi de position des éléments
    */
    void resetmatrice();

    /**
    *@fn setmatrice(Game_Object* obj, int x, int y)
    *@brief actualise dans la matrice, la position d'un élément (object) du jeu
    *@param obj élément à mettre dans la matrice
    *@param x position verticale de l'élément
    *@param y position horizontal de l'élément
    */
    void setmatrice(Game_Object* obj, int x, int y); 

    /**
    *@fn collision(Game_Object* obj1, Game_Object* obj2)
    *@brief vérifie s'il y a une collision entre 2 éléments du jeu (s'ils sont sur la même case)
    *@param obj1 premier objet avec lequel on veut regarder une collision
    *@param obj2 deuxieme objet avec lequel on veut regarder une collision
    *@return bool true si il y a collision et false sinon
    */
    bool collision(Game_Object* obj1, Game_Object* obj2);

    /**
    *@fn desplayscore(int s,int hs)
    *@brief affiche sur la ligne du bas le score le plus haut et le score de la game qui vient d'être finie
    *@param s score de la game qui vient d'être finie
    *@param hs le plus haut score depuis la dernière mise sous tension (ou reset)
    */
    void desplayscore(int s,int hs);

    /**
    *@fn affichedecompte(int i)
    *@brief affiche sur la ligne du bas un decompte partant de 9 indiquant le temps restant dans le mode de jeu 2
    *@param decompte decompte à afficher 
    */
    void affichedecompte(int decompte);

    /**
    *@fn continuousscore(int s)
    *@brief affiche en continue du score en temps réel dans les 2 modes de jeu en haut à gauche du LCD
    *@param s score à afficher
    */
    void continuousscore(int s);

    /**
    *@fn getmatrice()
    *@brief permet de récuperer la matrice actuelle de suivi de position des éléments du jeu
    *@return std::array<std::array<Game_Object*, 16>, 2> retourne l'attrubut matrice
    */
    std::array<std::array<Game_Object*, 16>, 2> getmatrice();

     /**
    *@fn getscreen()
    *@brief Retourne l’instance de l’écran LCD associé à l’objet LCD
    *@return rgb_lcd : copie de l'instance de la classe en question
    */
    rgb_lcd getscreen();

    /**
    *@fn setdarkmode()
    *@brief active le mode sombre et utilise la fonction de charge des dessins des éléments du mode sombre dans le LCD
    */
    void setdarkmode();

    /**
    *@fn setlightmode()
    *@brief active le mode normal et utilise la fonction de charge des dessins des éléments du mode normal dans le LCD
    */
    void setlightmode();

    /**
    *@fn dynamic_memory()
    *@brief charge soit les éléments sombres soit les élements normaux dans la mémoire du LCD en fonction le la valeur booléen "darkemode" qui indique si le mode de jeu présent est en mode nuit ou jour
    */
    void dynamic_memory();

    /**
    *@fn getdarkmode()
    *@brief permet de savoir si le mode actuel est le mode nuit ou le mode jour
    *@return bool : renvoie true si c'est la nuit, false si c'est le jour
    */
    bool getdarkmode();

    /**
    *@fn getr()
    *@brief permet de connaître le niveau d'intensité de rouge
    *@return int : renvoie un integer entre 0 et 255;
    */
    int getr();

     /**
    *@fn getg()
    *@brief permet de connaître le niveau d'intensité de vert
    *@return int : renvoie un integer entre 0 et 255;
    */
    int getg(); //Récupérer le niveau de vert

     /**
    *@fn getb()
    *@brief permet de connaître le niveau d'intensité de bleu
    *@return int : renvoie un integer entre 0 et 255;
    */
    int getb();
};

#endif
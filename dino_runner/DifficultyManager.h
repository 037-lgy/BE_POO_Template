#ifndef DIFFICULTYMANAGER_H_
#define DIFFICULTYMANAGER_H_

#include <Arduino.h>

class DifficultyManager{
    private:
        int spawndelaymode1;
        int spawndelaymode2;
        unsigned long harderdelay;
        int intensite;
    public:
        /**
         *@fn DifficultyManager()
        *@brief initialise les valeurs de scores et les temps de rafraîchissement
        */
        DifficultyManager();

        /**
         *@fn ~DifficultyManager()
        *@brief destructeur de la classe Difficulty Manager
        */
        ~DifficultyManager();
        
        /**
         *@fn resetspawn()
        *@brief Remet les valeurs initiales les variables de rapidités et la frequence de spawning des objets
        */
        void resetspawn();

        /**
         *@fn harder()
        *@brief method qui gère la difficulté du jeu en mettant à jour la rapidité et la frequence de spawning des objets
        */
        void harder();

        /**
         *@fn getspawndelaymode1()
        *@brief retourne la frequence d'apparition des objets pour le mode 1
        *@return int
        */
        const int getspawndelaymode1();

        /**
         *@fn getspawndelaymode2()
        *@brief retourne la frequence d'apparition des objets pour le mode 2
        *@return int
        */
        const int getspawndelaymode2();

        /**
         *@fn getintensite()
        *@brief retourne la rapidité de déplacement des objets
        *@return int
        */
        const int getintensite();
};

#endif
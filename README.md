# BE_POO_Template
Projet de base pour Ardouino

Actionneurs : 
- un buzzer sur D4 ? D9 ?
- lcd : I2C D1 et D2
- 2 led bouton : D0 et D5
- 1 led simple : D7

Capteurs : 
- 2 boutons : D6 et D3 état low : bouton pas appuyé
- potentiomètre : A0

Dans le run de l'application, 3 états possibles. 
- Si on est En_ATTENTE, on est sur un écran de démarrage du jeu, il faut appuyer sur un bouton pour déclancher l'écran de démarrage et passer à l'état en jeu
- Si on est EN_JEU, on a l'environnement de jeu qui apparait, quand on perd, on passe dans l'état EN_ATTENTE

Dans l'état en attente : "Démarrer le jeu : press red"
Dans l'état en jeu : mécaniques de jeu

8 objets maximum dans le jeu :
- Dino
- Cactus
- powerup
- oiseau
...

Il faudrait peut-être changer la matrice de l'écran pour prendre un type énuméré composé d'un objet et d'un char, si l'objet est nul, alors on affiche le char à la place.

A améliorer :
- faire des fonctions pour regrouper
- faire des commentaires

- Ne pas oublier de faire le destructeur !!!!

void Application::ColorManager(){
    float poten;
    poten = potentiometre->readsensor()*0.730476-5.11;
    if ((int) poten < 256) my_screen->setcouleur(0,(int) poten, 0);
    else if ((int) poten < 511) my_screen->setcouleur(255, (int) poten-256, 0);
    else my_screen->setcouleur(255, 255, (int) poten-512);
}

void ColorManager();

A supprimer : my_screen->setlightmode(); (244)

class spawnManager(){
    private:
        int spawndelaymode1;
        int spawndelaymode2;
        unsigned long harderdelay;
    public:
        spawnManager(){
            spawndelaymode1 = 4000;
            spawndelaymode2 = 800;
            harderdelay = millis();
        }
        void resetspawn(){
            spawndelaymode1 = 4000;
        }
        void harder(){
            if ((millis() - harderdelay) > 500) {
                spawndelaymode1 -= 100;
                harderdelay = millis();
            }
        }
        const int getspawndelaymode1(){return spawndelaymode1};
        const int getspawndelaymode2(){return spawndelaymode2};
}
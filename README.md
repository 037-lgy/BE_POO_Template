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
- Actualiser le score en haut à gauche en continu
- Cactus (et bird) en doube
- afficher meilleur score a la fin
- changer le delay de spawn et la vitesse des objets
- Voir quoi faire avec le potentiomètre
- Mettre des pièces pour augmenter le score
- Fonction pour la collision ?

- Ne pas oublier de faire le destructeur !!!!

Pour aller plus loin :
- inverser les couleurs du jeu (createchar en dynamique)
- Autre mode de jeu ??
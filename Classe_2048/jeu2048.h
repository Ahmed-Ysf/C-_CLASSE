/**
  @file jeu2048.h
  @brief déclaration de la classe du jeu 2048
  @details 2048 est un jeu de logique. Il se joue par tour sur une grille de 16 carrés.
           A chaque tour, une case de la grille est remplie avec un chiffre (2 ou 4).
           Le joueur peut alors décider de déplacer les cases soit vers le haut, le bas, la gauche ou la droite.
           Si deux cases adjacentes sont déplacées dans le même sens et portent un nombre identiques, elles sont additionnées.
           Ainsi, deux cases 4 forment une case 8 et libèrent une case.
           Le jeu se termine en victoire si le joueur arrive à former une case 2048 (2 puissance 11)
           et en échec si l'ensemble des cases sont remplies sans possibilité d'en fusionner au moins deux lors d'un déplacement.
           Attention, inutile de croire que l'on peut l'emporter en 5 minutes car arriver à 2048 en partant de deux cases remplies
           avec des 2 et en ayant la chance de former des combinaisons parfaites demandera quelque 1279 mouvements de pièces !
           Soit, plus d'une heure et demie de jeu, en partant sur un mouvement toutes les 5 secondes.
  @version 1.0
  @authors Philippe S & C
  @date 18 sept 2020
*/


#ifndef JEU2048_H
#define JEU2048_H

#include <time.h>
#include <stdlib.h>     /* srand, rand */
#include <iostream>

enum MODE_ALEATOIRE{
    POSITION,
    TUILE
};


class Jeu2048
{

public:
    Jeu2048();
    bool JouerCoup(char _direction);
    int  ObtenirNbCoups() const;
    int  ObtenirScore() const;
    void ObtenirGrille(int _grille[][4]);
    bool ObtenirResultat();

private:
    int  TirerAleatoire(const int _mode);
    void PlacerNouvelleTuile();
    bool Calculer();
    void Deplacer();
    void CalculerScore();
    bool RechercherFinDePartie();


    int grille[4][4];
    char direction;
    int nbCoups;
    int score;
    bool gagne;

};

#endif // JEU2048_H



/**
  @file jeu2048.cpp
  @brief implémentation de la classe du jeu 2048
  @version 1.0
  @authors Philippe S & C
  @date 18 sept 2020
*/

#include "jeu2048.h"

/**
 * @brief Jeu2048::ObtenirNbCoups
 * @return entier le nombre de coups
 */

int Jeu2048::ObtenirNbCoups() const
{
    return nbCoups;
}

/**
 * @brief Jeu2048::ObtenirScore
 * @return  entier Le score
 */
int Jeu2048::ObtenirScore() const
{
    return score;
}

/**
 * @brief Jeu2048::ObtenirGrille
 *        Recopie les valeurs de la grille du jeu
 *        dans le tableau donné en paramètre
 * @param _grille
 */

void Jeu2048::ObtenirGrille(int _grille[][4])
{
    for(int ligne = 0 ; ligne < 4 ; ligne++)
    {
        for (int colonne = 0 ; colonne < 4 ; colonne++)
        {
            _grille[ligne][colonne] = grille[ligne][colonne];
        }
    }
}

/**
 * @brief Jeu2048::Jeu2048
 *        Constructeur Initialise la grille du jeux en
 *        Plaçant des 0 dans chaque case puis place une
 *        nouvelle tuile de valeur 2 ou 4 à un emplacement
 *        libre sur la grille.
 */
Jeu2048::Jeu2048():
    nbCoups(0),
    score(0),
    gagne(false)
{
    srand(time(nullptr));
    for(int ligne = 0 ; ligne < 4 ; ligne++)
    {
        for (int colonne = 0 ; colonne < 4 ; colonne++)
        {
            grille[ligne][colonne] = 0;
        }
    }
    PlacerNouvelleTuile();
}

/**
 * @brief Jeu2048::JouerCoup
 *        Déplace le contenu de la grille en fonction de la direction demandée
 *        par le joueur et calcule les sommes éventuelles.
 *        Après le calcul des sommes, la grille doit à nouveau être déplacée.
 *        Si il y a eu une fusion, pour supprimer les 0 laissé après les fusions.
 * @param _direction
 * @return
 */
bool Jeu2048::JouerCoup(char _direction)
{
    direction = _direction;
    Deplacer();
    if(Calculer())
        Deplacer();
    CalculerScore();
    bool fin =  RechercherFinDePartie();
    if (!fin)
        PlacerNouvelleTuile();
    nbCoups++;
    return fin;
}

/**
 * @brief Jeu2048::TirerAleatoire
 *        Renvoie un entier
 *        pour _mode POSITION  entre 0 et 3
 *        pour _mode TUILE    soit 2 ou 4
 * @param _mode
 * @return integer la valeur du tirage
 */
int Jeu2048::TirerAleatoire(const int _mode)
{
    int retour;
    if(_mode == POSITION)
        retour = rand() % 4;
    else retour = (((rand() % 2) +1 ) * 2);
    return retour;
}

/**
 * @brief Jeu2048::PlacerNouvelleTuile
 */
void Jeu2048::PlacerNouvelleTuile()
{
    int ligne = TirerAleatoire(POSITION);
    int colonne = TirerAleatoire(POSITION);
    while(grille[ligne][colonne]!=0)
    {
        ligne = TirerAleatoire(POSITION);
        colonne = TirerAleatoire(POSITION);
    }
    grille[ligne][colonne] = TirerAleatoire(TUILE);
}

/**
 * @brief Jeu2048::Calculer
 *        Si deux cases adjacentes sont déplacées dans le même sens
 *        et portent un nombre identiques, elles sont additionnées.
 * @return bool true si une case a été libérée
 */
bool Jeu2048::Calculer()
{
    int ligne;
    int colonne;
    bool retour = false;
    switch (direction) {
    case 'G':
        for(ligne = 0 ; ligne < 4 ; ligne++)
        {
            for(colonne = 0 ; colonne < 3 ; colonne++)
            {
                if(grille[ligne][colonne]==grille[ligne][colonne+1])
                {
                    grille[ligne][colonne] = grille[ligne][colonne] * 2;
                    grille[ligne][colonne+1] = 0;
                    retour = true;
                }
            }
        }
        break;
    case 'D':
        for(ligne = 0 ; ligne < 4 ; ligne++)
        {
            for(colonne = 3 ; colonne > 0 ; colonne--)
            {
                if(grille[ligne][colonne]==grille[ligne][colonne-1])
                {
                    grille[ligne][colonne] = grille[ligne][colonne] * 2;
                    grille[ligne][colonne-1] = 0;
                    retour = true;
                }
            }
        }
        break;
    case 'B':
        for(colonne = 0 ; colonne < 4 ; colonne++)
        {
            for( ligne = 3 ; ligne > 0 ; ligne--)
            {

                if(grille[ligne][colonne]==grille[ligne-1][colonne])
                {
                    grille[ligne][colonne] = grille[ligne][colonne] * 2;
                    grille[ligne-1][colonne] = 0;
                    retour = true;
                }
            }
        }
        break;
    case 'H':
        for(colonne = 0 ; colonne < 4 ; colonne++)
        {
            for( ligne = 0 ; ligne < 3 ; ligne++)
            {
                if(grille[ligne][colonne]==grille[ligne+1][colonne])
                {
                    grille[ligne][colonne] = grille[ligne][colonne] * 2;
                    grille[ligne+1][colonne] = 0;
                    retour = true;
                }
            }
        }
        break;
    }
    return retour;
}

/**
 * @brief Jeu2048::Deplacer
 *        Deplace les cases dans la direction demandée
 */
void Jeu2048::Deplacer()
{
    int ligne;
    int colonne;
    for(int indice = 0 ; indice < 2 ; indice++)
    {
        switch (direction) {
        case 'G':
            for(ligne = 0 ; ligne < 4 ; ligne++)
            {
                for(colonne = 0 ; colonne < 3 ; colonne++)
                {
                    if(grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne][colonne+1];
                        grille[ligne][colonne+1] = 0;
                    }
                }
            }
            break;
        case 'D':
            for(ligne = 0 ; ligne < 4 ; ligne++)
            {
                for(colonne = 3 ; colonne > 0 ; colonne--)
                {
                    if(grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne][colonne-1];
                        grille[ligne][colonne-1] = 0;
                    }
                }
            }
            break;

        case 'B':
            for(colonne = 0 ; colonne < 4 ; colonne++)
            {
                for( ligne = 3 ; ligne > 0 ; ligne--)
                {
                    if(grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne-1][colonne];
                        grille[ligne-1][colonne] = 0;
                    }
                }
            }
            break;

        case 'H':

            for(colonne = 0 ; colonne < 4 ; colonne++)
            {
                for( ligne = 0 ; ligne < 3 ; ligne++)
                {
                    if(grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne+1][colonne];
                        grille[ligne+1][colonne] = 0;
                    }
                }
            }
            break;
        }
    }
}


/**
 * @brief Jeu2048::CalculerScore
 *        Le score est calculé en effectuant la somme de toutes les cases
 */
void Jeu2048::CalculerScore()
{
    int somme = 0;
    for(int ligne = 0 ; ligne < 4 ; ligne++)
    {
        for (int colonne = 0 ; colonne < 4 ; colonne++)
        {
            somme +=  grille[ligne][colonne];
        }
    }
    score = somme;
}

/**
 * @brief Jeu2048::RechercherFinDePartie
 *        Le jeu se termine en victoire si le joueur arrive à former une case 2048 (2 puissance 11)
 *        et en échec si l'ensemble des cases sont remplies sans possibilité d'en fusionner
 *        au moins deux lors d'un déplacement.
 * @return bool  true si partie terminée
 */

bool Jeu2048::RechercherFinDePartie()
{


    bool fin = false;


    int ligne = 0;

    int cpt = 0;  // compteur de cases vides

    while(fin == false && ligne < 4)
    {
        int colonne = 0;
        while(fin == false && colonne < 4)
        {
            if(grille[ligne][colonne] == 2048){
                fin = true;
                gagne = true;
            }
            if(grille[ligne][colonne] == 0)
                cpt++;
            colonne++;
        }
        ligne++;  // On passe à la ligne suivante

    }
    if(cpt == 0){   // si toutes les cases sont remplies alors le compteur est resté à zero
        fin = true;
    }
    return fin;


}

/**
 * @brief Jeu2048::ObtenirResultat
 *        Indique si la partie est gagnée ou perdue
 * @return bool true si la partie est gagnée
 */
bool Jeu2048::ObtenirResultat()
{
    return gagne;
}

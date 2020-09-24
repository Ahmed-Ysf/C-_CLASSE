#include <iostream>
#include <iomanip>
#include <string.h>

#include "jeu2048.h"

using namespace std;

void AfficherGrille(Jeu2048 &leJeu);

int main()
{
    Jeu2048 leJeu;
    char direction;
    bool finDePartie = false;

    do
    {
        AfficherGrille(leJeu);
        cin >> direction ;
        direction = toupper(direction);
        if(strchr("BHGD",direction) != nullptr)
        {
            finDePartie = leJeu.JouerCoup(direction);
        }
    } while( direction != 'F' && finDePartie == false);

    if (leJeu.ObtenirResultat())
        cout << "Vous avez gagnez " << endl;
    else {
        cout << "Vous avez perdu "  << endl;
    }
    return 0;
}

void AfficherGrille(Jeu2048 &leJeu)
{
    int laGrille[4][4];
    int leScore = leJeu.ObtenirScore();
    int leNombreDeCoups = leJeu.ObtenirNbCoups();

    leJeu.ObtenirGrille(laGrille);

#ifdef __linux__
        system("clear");
#elif _WIN32
        system("cls");
#else

#endif


    cout << "Score : " << leScore << " | Nombre de coups : " << leNombreDeCoups << " |" << endl << endl;
    for(int ligne = 0 ; ligne < 4 ; ligne++)
    {
        cout << '+' ;
        for(int indice= 0 ; indice <4 ; indice++)
            cout << setw(7) << setfill('-') << '+';

        cout << setfill(' ') << endl;
        cout << '|' ;
        for (int col = 0 ; col < 4 ; col++)
        {
            if(laGrille[ligne][col]>0)
                cout << setw(5) << laGrille[ligne][col] << " |" ;
            else
                cout << setw(7)<< '|';
        }
        cout << endl;
    }

    cout << '+' ;
    for(int indice= 0 ; indice <4 ; indice++)
        cout << setw(7) << setfill('-') << '+';
    cout << endl;
    cout << "Votre déplacement : H (haut), B (bas), D (droite), G (gauche) : " ;


}

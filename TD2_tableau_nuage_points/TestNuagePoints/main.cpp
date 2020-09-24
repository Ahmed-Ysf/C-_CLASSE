#include <iostream>
#define NB_RELEVE 5
using namespace std;

int main()
{
    cout << "Nuage de points!" << endl;
    unsigned short nuagePoints[NB_RELEVE];
    for (int i = 0; i < NB_RELEVE; i++ ){
        do{
            cin >> nuagePoints[i];
        }
        while (nuagePoints[i] <0 || nuagePoints [i] >4095);
    }

    // calcul de la moyenne
    float moyenne;
    float som;

    moyenne = som /NB_RELEVE;



    // Affichage des valeurs

   for(int i =0; i < NB_RELEVE -1; i++){
       cout << " Le coureur "<< i << " a eu la moyenne  " << nuagePoints[i] << "  " << endl;
   }

  return 0;

}










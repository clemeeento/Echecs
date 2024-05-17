#include "echiquier.h"

int ** initialisationPartie()
{
    int **initial = (int**)malloc(tailleTableau*sizeof(int*));
    for (int i=0; i<tailleTableau; i=i+1)
    {
        initial[i] = (int*)malloc(tailleTableau*sizeof(int));
    }
    // 0 : Case vide
    // 1 : Pion
    // 2 : Fou
    // 3 : Cavalier
    // 4 : Tour
    // 5 : Dame
    // 6 : Roi
    // 1x : Blancs
    // 2x : Noirs

    for(int i=0; i<tailleTableau;i=i+1) //Placement des pions et des cases vides
    {
        initial[1][i] = 11; // Pions Blanc
        initial[6][i] = 21; // Pions Noirs

        // Cases vides
        initial[2][i] = 0;
        initial[3][i] = 0;
        initial[4][i] = 0;
        initial[5][i] = 0;        
    }

    // Fous Blancs
    initial[0][2] = 12;
    initial[0][5] = 12;
    // Fous Noirs
    initial[7][2] = 22;
    initial[7][5] = 22;

    // Cavaliers Blancs
    initial[0][1] = 13;
    initial[0][6] = 13;
    // Cavaliers Noirs
    initial[7][1] = 23;
    initial[7][6] = 23;

    // Tours Blanches
    initial[0][0] = 14;
    initial[0][7] = 14;
    // Tours Noirs
    initial[7][0] = 24;
    initial[7][7] = 24;

    // Dame Blanche
    initial[0][4] = 15;
    // Dame Noir
    initial[7][4] = 25;

    // Roi Blanc
    initial[0][3] = 16;
    // Roi Noir
    initial[7][3] = 26;

    return initial;
}

int ** copieTableau(int **tableau)
{
    // Création d'un tableau de la même taille
    int **copie = (int**)malloc(tailleTableau*sizeof(int*));
    for (int i=0; i<tailleTableau; i=i+1)
    {
        copie[i] = (int*)malloc(tailleTableau*sizeof(int));
    }

    // Copie des valeurs
    for(int i=0; i<tailleTableau; i=i+1)
    {
        for(int j=0; j<tailleTableau; j=j+1)
        {
            copie[j][i] = tableau[j][i];
        }
    }

    return copie;
}

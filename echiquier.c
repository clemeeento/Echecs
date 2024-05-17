#include "echiquier.h"

int **initialisationPartie()
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
        initial[i][1] = 11; // Pions Blanc
        initial[i][6] = 21; // Pions Noirs

        // Cases vides
        initial[i][2] = 0;
        initial[i][3] = 0;
        initial[i][4] = 0;
        initial[i][5] = 0;        
    }

    // Fous Blancs
    initial[2][0] = 12;
    initial[5][0] = 12;
    // Fous Noirs
    initial[2][7] = 22;
    initial[5][7] = 22;

    // Cavaliers Blancs
    initial[1][0] = 13;
    initial[6][0] = 13;
    // Cavaliers Noirs
    initial[1][7] = 23;
    initial[6][7] = 23;

    // Tours Blanches
    initial[0][0] = 14;
    initial[7][0] = 14;
    // Tours Noirs
    initial[0][7] = 24;
    initial[7][7] = 24;

    // Dame Blanche
    initial[4][0] = 15;
    // Dame Noir
    initial[4][7] = 25;

    // Roi Blanc
    initial[3][0] = 16;
    // Roi Noir
    initial[3][7] = 26;

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
            copie[i][j] = tableau[i][j];
        }
    }

    return copie;
}

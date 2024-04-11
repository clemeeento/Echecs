#include "minmax.h"

void calculScore(item * noeud, int couleur)
{
    int score = 0;
    for(int i=0; i<tailleTableau; i=i+1)
    {
        for(int j=0; j<tailleTableau; j=j+1)
        {
            if(noeud->tableau[i][j]/10 == couleur)
            {
                score = score + noeud->tableau[i][j]%10;
            }
            else
            {
                score = score - noeud->tableau[i][j]%10;
            }
        }
    }
    if(estEchecMat(noeud->tableau, couleur))
    {
        score = score - 20;
    }
    noeud->score = score;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "item.h"
#include "liste.h"
#include "echiquier.h"
#include "deplacement.h"
#include "minmax.h"

void afficherTableau(int **tableau)
{
    printf("\n");
    for(int i=0; i<tailleTableau; i=i+1)
    {
        for(int j=0; j<tailleTableau; j=j+1)
        {
            printf("%d ", tableau[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}        


void testDeplacement(int ** tableau)
{
    int tour = 1;
    int initiale, finale;
    while(!estEchecMat(tableau, tour))
    {
        while(tour==1)
        {
            printf("Tour des blancs \n");
            printf("Entrer la position de la pièce que l'on veut deplacer :\n");
            scanf("%d",initiale);
            printf("Entrer position finale :\n");
            scanf("%d",finale);
            if(deplacementValide(tableau, initiale/10, initiale%10, finale/10, finale%10) && tableau[initiale/10][initiale%10]/10 == tour)
            {
                deplacement(tableau, initiale/10, initiale%10, finale/10, finale%10);  
                afficherTableau(tableau);    
                tour = 2; 
            }
            
        }

        while(tour==2)
        {
            printf("Tour des noirs \n");
            printf("Entrer la position de la pièce que l'on veut deplacer :\n");
            scanf("%d",initiale);
            printf("Entrer position finale :\n");
            scanf("%d",finale);
            if(deplacementValide(tableau, initiale/10, initiale%10, finale/10, finale%10) && tableau[initiale/10][initiale%10]/10 == tour)
            {
                deplacement(tableau, initiale/10, initiale%10, finale/10, finale%10);  
                tour = 1; 
            }
        }
    }
}


void testpartie(int ** tableau)
{   int a = 1;
    int i = 0 ; 
    item * noeud = creerItem();
    noeud->tableau = tableau;
        afficherTableau(noeud->tableau);        

    noeud = trouverMeilleurCoup(noeud, a);
    afficherTableau(noeud->tableau);        
    

}

int main()
{
    int **tableau = initialisationPartie();
    testpartie(tableau);
    return 0;
}
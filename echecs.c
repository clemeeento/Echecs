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
void startGame()
{
    int **tableau = initialisationPartie();
    int initialX, initialY, finalX, finalY;
    item * noeud = creerItem();
    noeud->tableau = tableau;
    afficherTableau(noeud->tableau);
    int joueur= 1 ; 
    while(estEchecMat(noeud->tableau, joueur) == 0)
    {
        if(joueur == 1)
        {
            joueur = 2;
    printf("Choissiseez la ligne et en suite la colonne de la piece que vous voulez deplacer\n");
    scanf("%d", &initialX);
    scanf("%d", &initialY);
    scanf("%d", &finalX);
    scanf("%d", &finalY);
    if(deplacementValide(noeud->tableau, initialX, initialY, finalX, finalY) == 1){
    deplacement(noeud->tableau, initialX, initialY, finalX, finalY);
    afficherTableau(noeud->tableau);}
        }
        else
        {
            noeud = trouverMeilleurCoup(noeud, joueur);
            afficherTableau(noeud->tableau);
            joueur = 1;

        }
    

    




    
    
    
    }}

void testpartie(int ** tableau)
{   int a = 1;
    int i = 0 ; 
    item * noeud = creerItem();

    while (estEchecMat(tableau, a) == 0 )
    {
        if(a == 1)
        {
            a = 2;
        }
        else
        {
            a = 1;
        }
    noeud->tableau = tableau;
        afficherTableau(noeud->tableau);        

    noeud = trouverMeilleurCoup(noeud, a);
    afficherTableau(noeud->tableau);   
    tableau = noeud->tableau;     
    i++;}
      
    

}

int main()
{
    startGame( );
    return 0;
}
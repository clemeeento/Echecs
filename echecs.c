#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "item.h"
#include "liste.h"
#include "echiquier.h"
#include "deplacement.h"
#include "minmax.h"
#include "graphique.h"

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



int main()
{
    int quit = 0;
    int tour = 1;
    int x, y;
    int initialX, initialY, finalX, finalY;

    int ** echiquier = initialisationPartie();


    // Initialiser SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Erreur lors de l'initialisation de SDL: %s\n", SDL_GetError());
        return 0;
    }
    
    // Créer une fenêtre
    SDL_Window* window = SDL_CreateWindow("Échecs", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LARGEUR_FENETRE, HAUTEUR_FENETRE, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Erreur lors de la création de la fenêtre: %s\n", SDL_GetError());
        SDL_Quit();
        return 0;
    }
    
    // Créer un renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("Erreur lors de la création du renderer: %s\n", SDL_GetError());
        SDL_Quit();
        return 0;
    }
    
    // Charger les textures des pièces
    SDL_Texture** pieces = chargerPieces(renderer);
    if (pieces == NULL)
    {
        printf("Erreur lors du chargement des textures des pièces\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
    }
    
    // Boucle principale
    SDL_Event event;
    while (!quit)
    {
        if (SDL_WaitEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                SDL_GetMouseState(&y, &x);
                
                // Convertir les coordonnées de la souris en coordonnées de l'échiquier
                initialX = x / (LARGEUR_FENETRE / tailleTableau);
                initialY = y / (HAUTEUR_FENETRE / tailleTableau);
            }   
            if(event.type == SDL_MOUSEBUTTONUP)
            {
                SDL_GetMouseState(&y, &x);
                
                // Convertir les coordonnées de la souris en coordonnées de l'échiquier
                finalX = x / (LARGEUR_FENETRE / tailleTableau);
                finalY = y / (HAUTEUR_FENETRE / tailleTableau);

                printf("Deplacement de (%d, %d) vers (%d, %d)\n", initialX, initialY, finalX, finalY); 
                printf("Piece de la case de depart : %d\n", echiquier[initialY][initialX]);
                printf("Piece de la case d'arrivee : %d\n", echiquier[finalY][finalX]);

                if(echiquier[initialY][initialX]/10 == tour)
                {
                    if(deplacementValide(echiquier, initialX, initialY, finalX, finalY))
                    {
                        deplacement(echiquier, initialX, initialY, finalX, finalY);
                        afficherTableau(echiquier);
                        tour = 3 - tour;
                    }
                }
            }
        }

        // Effacer le renderer
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        // Afficher l'échiquier et les pieces
        afficherEchiquier(renderer);
        afficherPieces(pieces, echiquier, renderer);
        
        // Mettre à jour l'affichage
        SDL_RenderPresent(renderer);
    }
    
    // Libérer les ressources
    for (int i = 0; i < 12; i++)
    {
        SDL_DestroyTexture(pieces[i]);
    }
    free(pieces);
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

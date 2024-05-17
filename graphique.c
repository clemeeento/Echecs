#include <SDL2/SDL.h>

#include "graphique.h"

void afficherEchiquier(SDL_Renderer* renderer)
{
    // Dimensions d'une case de l'échiquier
    int largeurCase = LARGEUR_FENETRE / tailleTableau;
    int hauteurCase = HAUTEUR_FENETRE / tailleTableau;
    
    // Couleurs des cases
    SDL_Color couleurBlanc = {255, 255, 255, 255};
    SDL_Color couleurGris = {159, 159, 159, 255};
    
    // Parcourir les cases de l'échiquier
    for (int i = 0; i < tailleTableau; i++)
    {
        for (int j = 0; j < tailleTableau; j++)
        {
            // Calculer les coordonnées de la case
            int x = i * largeurCase;
            int y = j * hauteurCase;
            
            // Dessiner la case
            SDL_Rect caseRect = {x, y, largeurCase, hauteurCase};
            if ((i + j) % 2 == 0)
            {
                SDL_SetRenderDrawColor(renderer, couleurBlanc.r, couleurBlanc.g, couleurBlanc.b, couleurBlanc.a);
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, couleurGris.r, couleurGris.g, couleurGris.b, couleurGris.a);
            }
            SDL_RenderFillRect(renderer, &caseRect);
            
        }
    }
}

// Charge une texture à partir d'un fichier image
// path: le chemin du fichier image
// renderer: le renderer SDL sur lequel la texture sera rendue
// Retourne la texture chargée ou NULL en cas d'erreur
SDL_Texture* chargerTexture(const char* chemin, SDL_Renderer* renderer) 
{
    // Charge l'image à partir du fichier
    SDL_Surface* surfaceChargee = SDL_LoadBMP(chemin);
    if (surfaceChargee == NULL) 
    {
        printf("Impossible de charger l'image %s! SDL_Error: %s\n", chemin, SDL_GetError());
        return NULL;
    }
    
    // Crée une texture à partir de la surface chargée
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surfaceChargee);
    
    // Libère la surface chargée
    SDL_FreeSurface(surfaceChargee);
    
    return texture;
}

SDL_Texture** chargerPieces(SDL_Renderer* renderer) 
{
    SDL_Texture** pieces = malloc(12 * sizeof(SDL_Texture*));
    
    // Charger les textures des pièces blanches
    pieces[0] = chargerTexture("images/pion_blanc.bmp", renderer);
    pieces[1] = chargerTexture("images/fou_blanc.bmp", renderer);
    pieces[2] = chargerTexture("images/cavalier_blanc.bmp", renderer);
    pieces[3] = chargerTexture("images/tour_blanc.bmp", renderer);
    pieces[4] = chargerTexture("images/reine_blanc.bmp", renderer);
    pieces[5] = chargerTexture("images/roi_blanc.bmp", renderer);

    // Charger les textures des pièces noires
    pieces[6] = chargerTexture("images/pion_noir.bmp", renderer);
    pieces[7] = chargerTexture("images/fou_noir.bmp", renderer);
    pieces[8] = chargerTexture("images/cavalier_noir.bmp", renderer);
    pieces[9] = chargerTexture("images/tour_noir.bmp", renderer);
    pieces[10] = chargerTexture("images/reine_noir.bmp", renderer);
    pieces[11] = chargerTexture("images/roi_noir.bmp", renderer);
    
    return pieces;
}

void afficherPieces(SDL_Texture** pieces, int ** echiquier, SDL_Renderer* renderer)
{
    // Dimensions d'une case de l'échiquier
    int largeurCase = LARGEUR_FENETRE / tailleTableau;
    int hauteurCase = HAUTEUR_FENETRE / tailleTableau;
    int x, y;

    // Parcourir les cases de l'échiquier
    for (int i = 0; i < tailleTableau; i++)
    {
        for (int j = 0; j < tailleTableau; j++)
        {
            // Calculer les coordonnées de la case
            x = i * largeurCase;
            y = j * hauteurCase;
            
            // Dessiner la pièce sur la case si elle existe
            int piece = echiquier[i][j];
            if (piece != 0)
            {
                if(piece==11) // Pion blanc 
                {
                    SDL_Texture* texture = pieces[0];
                    SDL_Rect pieceRect = {x, y, largeurCase, hauteurCase};
                    SDL_RenderCopy(renderer, texture, NULL, &pieceRect);
                }
                if(piece==12) // Fou blanc 
                {
                    SDL_Texture* texture = pieces[1];
                    SDL_Rect pieceRect = {x, y, largeurCase, hauteurCase};
                    SDL_RenderCopy(renderer, texture, NULL, &pieceRect);
                }
                if(piece==13) // Cavalier blanc 
                {
                    SDL_Texture* texture = pieces[2];
                    SDL_Rect pieceRect = {x, y, largeurCase, hauteurCase};
                    SDL_RenderCopy(renderer, texture, NULL, &pieceRect);
                }
                if(piece==14) // Tour blanc 
                {
                    SDL_Texture* texture = pieces[3];
                    SDL_Rect pieceRect = {x, y, largeurCase, hauteurCase};
                    SDL_RenderCopy(renderer, texture, NULL, &pieceRect);
                }
                if(piece==15) // Reine blanche
                {
                    SDL_Texture* texture = pieces[4];
                    SDL_Rect pieceRect = {x, y, largeurCase, hauteurCase};
                    SDL_RenderCopy(renderer, texture, NULL, &pieceRect);
                }
                if(piece==16) // Roi blanc
                {
                    SDL_Texture* texture = pieces[5];
                    SDL_Rect pieceRect = {x, y, largeurCase, hauteurCase};
                    SDL_RenderCopy(renderer, texture, NULL, &pieceRect);
                }
                if(piece==21) // Pion noir 
                {
                    SDL_Texture* texture = pieces[6];
                    SDL_Rect pieceRect = {x, y, largeurCase, hauteurCase};
                    SDL_RenderCopy(renderer, texture, NULL, &pieceRect);
                }
                if(piece==22) // Fou noir 
                {
                    SDL_Texture* texture = pieces[7];
                    SDL_Rect pieceRect = {x, y, largeurCase, hauteurCase};
                    SDL_RenderCopy(renderer, texture, NULL, &pieceRect);
                }
                if(piece==23) // Cavalier noir 
                {
                    SDL_Texture* texture = pieces[8];
                    SDL_Rect pieceRect = {x, y, largeurCase, hauteurCase};
                    SDL_RenderCopy(renderer, texture, NULL, &pieceRect);
                }
                if(piece==24) // Tour noir 
                {
                    SDL_Texture* texture = pieces[9];
                    SDL_Rect pieceRect = {x, y, largeurCase, hauteurCase};
                    SDL_RenderCopy(renderer, texture, NULL, &pieceRect);
                }
                if(piece==25) // Reine noire
                {
                    SDL_Texture* texture = pieces[10];
                    SDL_Rect pieceRect = {x, y, largeurCase, hauteurCase};
                    SDL_RenderCopy(renderer, texture, NULL, &pieceRect);
                }
                if(piece==26) // Roi noir
                {
                    SDL_Texture* texture = pieces[11];
                    SDL_Rect pieceRect = {x, y, largeurCase, hauteurCase};
                    SDL_RenderCopy(renderer, texture, NULL, &pieceRect);
                }
            }
        }
    }
}


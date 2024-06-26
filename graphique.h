#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#define SDL_MAIN_HANDLED 
#include <SDL2/SDL.h>

#include "echiquier.h"

#define LARGEUR_FENETRE 800
#define HAUTEUR_FENETRE 800

void afficherEchiquier(SDL_Renderer* renderer);
SDL_Texture* chargerTexture(const char* chemin, SDL_Renderer* renderer);
SDL_Texture** chargerPieces(SDL_Renderer* renderer);
void afficherPieces(SDL_Texture** pieces, char ** echiquier, SDL_Renderer* renderer);


#endif
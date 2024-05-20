#ifndef TABLEAU_H
#define TABLEAU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "liste.h"

#define tailleTableau 8

char **initialisationPartie(); // Initialise le tableau de jeu
char ** copieTableau(char **tableau); // Copie le tableau de jeu
void deplacement(char **tableau, int initialX, int initialY, int finalX, int finalY); // Déplace une pièce

#endif

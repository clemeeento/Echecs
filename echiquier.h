#ifndef TABLEAU_H
#define TABLEAU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "item.h"
#include "liste.h"

#define tailleTableau 8

int **initialisationPartie(); // Initialise le tableau de jeu
int ** copieTableau(int **tableau); // Copie le tableau de jeu
void deplacement(int **tableau, int initialX, int initialY, int finalX, int finalY); // Déplace une pièce

#endif

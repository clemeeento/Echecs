#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "echiquier.h"

int positionValidePion(char ** tableau, int initialX, int initialY, int finalX, int finalY);
int positionValideFou(char ** tableau, int initialX, int initialY, int finalX, int finalY);
int positionValideCavalier(char ** tableau, int initialX, int initialY, int finalX, int finalY);
int positionValideTour(char ** tableau, int initialX, int initialY, int finalX, int finalY);
int positionValideDame(char ** tableau, int initialX, int initialY, int finalX, int finalY);
int positionValideRoi(char ** tableau, int initialX, int initialY, int finalX, int finalY);
int positionValide(char ** tableau, int initialX, int initialY, int finalX, int finalY);

int estEchec(char ** tableau, int couleur);
int deplacementValide(char ** tableau, int initialX, int initialY, int finalX, int finalY);

int estEchecMat(char ** tableau, int couleur);

void deplacement(char **tableau, int initialX, int initialY, int finalX, int finalY);

#endif

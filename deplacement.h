#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "item.h"
#include "liste.h"
#include "echiquier.h"

int positionValidePion(int ** tableau, int initialX, int initialY, int finalX, int finalY);
int positionValideFou(int ** tableau, int initialX, int initialY, int finalX, int finalY);
int positionValideCavalier(int ** tableau, int initialX, int initialY, int finalX, int finalY);
int positionValideTour(int ** tableau, int initialX, int initialY, int finalX, int finalY);
int positionValideDame(int ** tableau, int initialX, int initialY, int finalX, int finalY);
int positionValideRoi(int ** tableau, int initialX, int initialY, int finalX, int finalY);
int positionValide(int ** tableau, int initialX, int initialY, int finalX, int finalY);

int estEchec(int ** tableau, int couleur, int posX, int posY);
int deplacementValide(int ** tableau, int initialX, int initialY, int finalX, int finalY);

int estEchecMat(int ** tableau, int couleur);

#endif

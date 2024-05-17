#ifndef MINMAX_H
#define MINMAX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "item.h"
#include "liste.h"
#include "echiquier.h"
#include "deplacement.h"

#define PROFONDEUR 4

void calculScore(item * noeud, int couleur);
liste * generationCoups(item * noeud, int couleur);
item * remonterArbre(item * noeud);
int ** minmax(item * noeud, item * meilleurCoup, int meilleurScore, int couleur, int profondeur);

#endif
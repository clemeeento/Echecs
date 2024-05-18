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

#define PROFONDEUR 3
#define COULEUR_IA 2

void calculScore(item * noeud);
liste * generationCoups(item * noeud, int couleur);
item * remonterArbre(item * noeud);
char ** minmax(item * noeud, item * meilleurCoup, int meilleurScore, int profondeur);

void afficherTableau(char **tableau);
#endif
#ifndef MINMAX_H
#define MINMAX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "liste.h"
#include "echiquier.h"
#include "deplacement.h"

#define PROFONDEUR 5
#define COULEUR_IA 2

typedef struct 
{
    char **tableau;
    int score;
} coup;

int comparerCoup(const void *a, const void *b);
int evaluerMobilité(char ** tableau, int couleur);
int calculScore(char ** tableau, int scoreParent);
liste * generationCoups(item * noeud, int couleur);
char ** remonterArbre(item * noeud);
char ** minmax(item * noeud, char ** meilleurCoup, int meilleurScore);

void afficherTableau(char **tableau);

#endif
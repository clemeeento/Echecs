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

#define PROFONDEUR 5

int calculScore(item * noeud, int couleur);
void generationCoupsRec(item *noeud, liste *coups, int couleur, int profondeur) ;
liste *generationCoups2(item *noeud, int couleur) ; 
liste * generationCoups(item * noeud, int couleur);
item *trouverMeilleurPremierCoup(item *noeud, int couleur) ;
void affichetouslescoupsRec(item * noeud);
void affichetouslescoups(liste * coups);
item *trouverMeilleurCoup(item *etatInitial, int couleur) ; 
int minimax(item *noeud, int profondeur, int couleur, int maximizingPlayer);
int min(int a, int b) ;
int max(int a, int b) ;

#endif
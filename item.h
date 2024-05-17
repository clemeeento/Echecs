#ifndef ITEM_H
#define ITEM_H

struct item_s;

typedef struct item_s 
{
    int taille; //Taille du tableau
    char **tableau; //Tableau d'entiers qui représente l'etat du jeu
    int profondeur;
    int score;
    struct item_s *parent, *fils; //Nécessaire pour la structure de l'arbre
    struct item_s *precedent, *suivant; //Nécessaire pour la structure de la liste
} item;

#endif 

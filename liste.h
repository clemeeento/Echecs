#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


struct item_s;

typedef struct item_s 
{
    int taille;
    char **tableau; //Tableau d'entiers qui représente l'etat du jeu
    int profondeur;
    int score;
    struct item_s *parent; //Nécessaire pour la structure de l'arbre
    struct item_s *precedent, *suivant; //Nécessaire pour la structure de la liste
} item;

typedef struct 
{
    int nombreElements;
    item *premier;
    item *dernier;
} liste;



int comparaisonTableau(char ** board1, char ** board2, int taille); //Compare deux tableaux
item * creerItem(); // Créer un item
void libererTableau(char **tableau, int taille); // Libérer un tableau
void libererItem(item * noeud); // Libérer un item
void remplireItem(item * noeud, char ** tableau, int taille); // Remplir un item
liste * creerListe(); // Créer une liste
void libererListe(liste * l); // Libérer une liste
int nombreElements(liste * l); // Nombre d'éléments dans la liste
item *dansListe(liste * l, char **tableau, int taille); // Recherche d'un item dans la liste
void retirerItem(liste * l, item * noeud); // Retirer un item de la liste
item * retirerPremier(liste * l); // Retirer le premier item de la liste
item * retirerDernier(liste * l); // Retirer le dernier item de la liste    
void ajouterPremier(liste * l, item * noeud); // Ajouter un item en premier dans la liste
void ajouterDernier(liste * l, item * noeud); // Ajouter un item en dernier dans la liste
void afficherListe(liste * l); // Afficher la liste


#endif

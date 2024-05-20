#include "liste.h"

int comparaisonTableau(char ** tableau1, char ** tableau2, int taille)
{
	for(int i = 0;i<taille;i=i+1)
	{
        for(int j=0;j<taille;j=j+1)
        {
            if(tableau1[i][j]!=tableau2[i][j])
		    {
			    return 0;
		    }
        }
	}
	return 1;
}

item * creerItem() 
{
    item * noeud = (item *)malloc(sizeof(item));

    noeud->taille = 0;
    noeud->tableau = NULL;
    noeud->profondeur = 0;
    noeud->score = 0;
    noeud->parent = NULL;
    noeud->precedent = NULL;
    noeud->suivant = NULL;

    return noeud;
}

void libererTableau(char **tableau, int taille) 
{
    for(int i = 0; i < taille; i=i+1) 
    {
        if(tableau[i] != NULL) 
        {
            free(tableau[i]);
        }
    }
    free(tableau);
}

void libererItem(item *noeud) 
{

    if(noeud != NULL) 
    {
        if(noeud->tableau != NULL) 
        {
            libererTableau(noeud->tableau, noeud->taille);
        }
        else
        {
            printf("Erreur : tableau NULL lors de la liberation\n");
            fflush(stdout);
        }
        free(noeud);
    }
    else
    {
        printf("Erreur : noeud NULL lors de la liberation\n");
        fflush(stdout);
    }
}

liste * creerListe() 
{
    liste * l = (liste *)malloc(sizeof(liste));

    l->nombreElements = 0;
    l->premier = NULL;
    l->dernier = NULL;

    return l;
}

void libererListe(liste * l) 
{
    item * noeud = l->premier;
    item * suivant = NULL;

    while (noeud != NULL) 
    {
        suivant = noeud->suivant;
        libererItem(noeud);
        noeud = suivant;
    }

    free(l);
}

int nombreElements(liste * l) 
{
    return l->nombreElements;
}


void retirerItem(liste *l, item *noeud ) 
{
	if(noeud->suivant==NULL && noeud->precedent==NULL) //Cas unique élément
	{
		l->premier=NULL;
		l->dernier=NULL;
	}

	else if(noeud->suivant==NULL && noeud->precedent!=NULL) //Cas dernier élément
	{
		l->dernier=noeud->precedent;
		noeud->precedent->suivant=NULL;
		noeud->precedent=NULL;
	}

	else if(noeud->precedent==NULL && noeud->suivant!=NULL) //Cas premier élément
	{
		l->premier=noeud->suivant;
		noeud->suivant->precedent=NULL;
		noeud->suivant=NULL;
	}

	else //Cas élément au milieu
	{
		noeud->precedent->suivant=noeud->suivant;
		noeud->suivant->precedent=noeud->precedent;
		noeud->suivant=NULL;
		noeud->precedent=NULL;
	}

	l->nombreElements = l->nombreElements-1;
}

item * retirerPremier(liste * l) 
{
    if(l->premier == NULL)
    {
        return NULL;
    }
    else
    {
        item * noeud = l->premier;
        retirerItem(l, noeud);
        return noeud;
    }
}

item * retirerDernier(liste * l) 
{
    if(l->dernier == NULL)
    {
        return NULL;
    }
    else
    {
        item * noeud = l->dernier;
        retirerItem(l, noeud);
        return noeud;
    }
}

void ajouterPremier(liste * l, item * noeud) 
{
    if (l->premier == NULL) 
    {
        l->premier = noeud;
        l->dernier = noeud;
        noeud->precedent = NULL;
        noeud->suivant = NULL;
    } 
    else 
    {
        noeud->suivant = l->premier;
        l->premier->precedent = noeud;
        l->premier = noeud;
        noeud->precedent = NULL;
    }

    l->nombreElements = l->nombreElements + 1;
}

void ajouterDernier(liste * l, item * noeud) 
{
    if (l->dernier == NULL) 
    {
        l->premier = noeud;
        l->dernier = noeud;
        noeud->precedent = NULL;
        noeud->suivant = NULL;
    } 
    else 
    {
        noeud->precedent = l->dernier;
        l->dernier->suivant = noeud;
        l->dernier = noeud;
        noeud->suivant = NULL;
    }

    l->nombreElements = l->nombreElements + 1;
}
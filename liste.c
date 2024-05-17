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

void libererItem(item * noeud) 
{
    if ((noeud != NULL) && (noeud->tableau != NULL)) 
    {
        free(noeud->tableau);
    }
    free(noeud);
}

void remplireItem(item * noeud, char ** tableau, int taille) 
{
    noeud->taille = taille;
    noeud->tableau = (char **)malloc(taille * sizeof(char *));

    for (int i = 0; i < taille; i=i+1) 
    {
        noeud->tableau[i] = (char *)malloc(taille * sizeof(int));
        for (int j = 0; j < taille; j=j+1) 
        {
            noeud->tableau[i][j] = tableau[i][j];
        }
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

item *dansListe(liste * l, char ** tableau, int taille) 
{
    int i;
	int nbElements;
	item *noeud;
	if(l->nombreElements==0)
	{
		return NULL;
	}
	else
	{
		nbElements = nombreElements(l);
		noeud = l->premier;
		for(i=0;i<nbElements;i=i+1)
		{
			taille = noeud->taille;
			if(comparaisonTableau(tableau, noeud->tableau, taille) == 1)
			{
				return noeud;
			}
			noeud=noeud->suivant;
		}
	}

	return NULL;
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

void afficherListe(liste * l) 
{
    item * noeud = l->premier;

    while (noeud != NULL) 
    {
        for(int i=0; i<noeud->taille; i=i+1)
        {
            for(int j=0; j<noeud->taille; j=j+1)
            {
                printf("%d ", noeud->tableau[j][i]);
            }
            printf("\n");
        }
        printf("\n");
        noeud = noeud->suivant;
    }
}


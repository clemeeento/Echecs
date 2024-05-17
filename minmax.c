#include "minmax.h"

void calculScore(item * noeud, int couleur)
{
    int score = 0;
    for(int i=0; i<tailleTableau; i=i+1)
    {
        for(int j=0; j<tailleTableau; j=j+1)
        {
            if(noeud->tableau[i][j]/10 == couleur)
            {
                if(noeud->tableau[i][j]%10 == 1) // Pion
                {
                    score = score + 1;
                }
                else if(noeud->tableau[i][j]%10 == 2) // Cavalier
                {
                    score = score + 3;
                }
                else if(noeud->tableau[i][j]%10 == 3) // Fou
                {
                    score = score + 3;
                }
                else if(noeud->tableau[i][j]%10 == 4) // Tour
                {
                    score = score + 5;
                }
                else if(noeud->tableau[i][j]%10 == 5) // Dame
                {
                    score = score + 9;
                }
            }
            else
            {
                if(noeud->tableau[i][j]%10 == 1) // Pion
                {
                    score = score - 1;
                }
                else if(noeud->tableau[i][j]%10 == 2) // Cavalier
                {
                    score = score - 3;
                }
                else if(noeud->tableau[i][j]%10 == 3) // Fou
                {
                    score = score - 3;
                }
                else if(noeud->tableau[i][j]%10 == 4) // Tour
                {
                    score = score - 5;
                }
                else if(noeud->tableau[i][j]%10 == 5) // Dame
                {
                    score = score - 9;
                }
            }
        }
    }
    if(couleur == 1)
    {
        if(estEchecMat(noeud->tableau, 1))
        {
            score = score - 100;
        }
    }
    else
    {
        if(estEchecMat(noeud->tableau, 2))
        {
            score = score - 100;
        }
    }
    noeud->score = noeud->score + score;
}

liste * generationCoups(item * noeud, int couleur)
{
    liste * coups = creerListe();
    item * coup = NULL;

    // On parcourt le tableau pour trouver les pièces de la couleur du joueur
    for(int i=0; i<tailleTableau; i=i+1) // i = ligne de la pièce
    {
        for(int j=0; j<tailleTableau; j=j+1) // j = colonne de la pièce
        {
            // Si la pièce est de la couleur du joueur
            if(noeud->tableau[i][j]/10 == couleur)
            {
                // On parcourt le tableau pour trouver les cases où la pièce peut se déplacer
                for(int k=0; k<tailleTableau; k=k+1) // k = ligne de la case
                {
                    for(int l=0; l<tailleTableau; l=l+1) // l = colonne de la case
                    {
                        // Si le déplacement est valide
                        if(deplacementValide(noeud->tableau, i, j, k, l))
                        {
                            coup = creerItem();
                            coup->tableau = copieTableau(noeud->tableau);
                            deplacement(coup->tableau, i, j, k, l);
                            coup->profondeur = noeud->profondeur + 1;
                            coup->parent = noeud;
                            coup->taille = tailleTableau;
                            calculScore(coup, couleur);
                            ajouterDernier(coups, coup);
                        }
                    }
                }
            }
        }
    }
    return coups;
}

item * remonterArbre(item * noeud)
{
    item * tmp = noeud;
    while(tmp->profondeur != 1)
    {
        tmp = tmp->parent;
    }
    return tmp;
}

char ** minmax(item * noeud, item * meilleurCoup, int meilleurScore, int couleur, int profondeur)
{
    if(noeud->profondeur == 1 && noeud->suivant == NULL)
    {
        char ** tableau = copieTableau(meilleurCoup->tableau);

        while(noeud->precedent != NULL)
        {
            libererItem(noeud);
            noeud = noeud->precedent;
        }

        return tableau;
    }
    else
    {
        if(noeud->profondeur < profondeur)
        {

            liste * coups = generationCoups(noeud, couleur);
            noeud = coups->premier;

            minmax(noeud, meilleurCoup, meilleurScore, couleur, profondeur);
        }

        else
        {
            while(noeud->suivant != NULL)
            {
                if(noeud->score > meilleurScore)
                {
                    meilleurScore = noeud->score;
                    meilleurCoup = remonterArbre(noeud);
                }

                noeud = noeud->suivant;
                libererItem(noeud->precedent);
            }

            noeud = noeud->parent;

            while(noeud->suivant == NULL)
            {
                noeud = noeud->parent;
            }

            noeud = noeud->suivant;
            minmax(noeud, meilleurCoup, meilleurScore, couleur, profondeur);
        }
    }
}

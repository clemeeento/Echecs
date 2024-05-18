#include "minmax.h"

void afficherTableau(char **tableau)
{
    for(int i = 0; i < tailleTableau; i++)
    {
        for(int j = 0; j < tailleTableau; j++)
        {
            if(tableau[j][i] == 0)
            {
                printf("00 ");
            }
            else
            {
                printf("%d ", tableau[j][i]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void calculScore(item * noeud)
{
    int score = 0;
    for(int i=0; i<tailleTableau; i=i+1)
    {
        for(int j=0; j<tailleTableau; j=j+1)
        {
            if(noeud->tableau[i][j]/10 == COULEUR_IA)
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
    if(estEchecMat(noeud->tableau, COULEUR_IA))
    {
        score = score - 100;
    }

    if(estEchecMat(noeud->tableau, 3 - COULEUR_IA))
    {
        score = score + 100;
    }

    noeud->score = noeud->score + score;
}

liste * generationCoups(item * noeud, int couleur)
{
    liste * coups = creerListe();
    item * coup = NULL;

    if(noeud == NULL)
    {
        printf("Noeud Null lors de la géneration\n");
    }

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
                            calculScore(coup);
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

char ** minmax(item * noeud, item * meilleurCoup, int meilleurScore, int profondeur)
{   
    int couleur;

    // Cas Terminal, on a fini de parcourir l'arbre
    if(noeud->profondeur == 1 && noeud->suivant == NULL)
    {
        printf("Cas terminal\n");

        if(meilleurCoup == NULL) // Si c'est le seul coup possible
        {
            meilleurCoup = noeud;
        }

        char ** tableau = copieTableau(meilleurCoup->tableau);

        while(noeud->precedent != NULL)
        {
            noeud = noeud->precedent;
            libererItem(noeud->suivant);
        }

        return tableau;
    }
    else
    {
        // Si on est à une profondeur inférieure à la profondeur maximale ou si le score est supérieur à -20
        // On génère les coups suivants
        if(noeud->profondeur < profondeur && noeud->score > -20)
        {
            //printf("Profondeur : %d\n", noeud->profondeur);
            if(noeud->profondeur%2 == 0)
            {
                couleur = COULEUR_IA;
            }
            else
            {
                couleur = 3 - COULEUR_IA;
            }

            liste * coups = generationCoups(noeud, couleur);
            noeud = coups->premier;
            printf("Coups generes, profondeur : %d\n", noeud->profondeur);
            minmax(noeud, meilleurCoup, meilleurScore, profondeur);
        }
        else
        {
            // Si on est à la profondeur maximale
            if(noeud->profondeur == profondeur)
            {
                // On compare les scores des noeuds
                while(noeud->suivant != NULL)
                {
                    // Si le score du noeud est supérieur au meilleur score
                    if(noeud->score > meilleurScore)
                    {
                        meilleurScore = noeud->score;
                        meilleurCoup = remonterArbre(noeud);
                    }

                    noeud = noeud->suivant;
                    libererItem(noeud->precedent); // On libère la mémoire du noeud précédent
                }

                // On remonte l'arbre
                    item * tmp = noeud;
                    noeud = noeud->parent;
                    libererItem(tmp);

                while(noeud->suivant == NULL && noeud->profondeur != 1)
                {
                    item * tmp = noeud;
                    noeud = noeud->parent;
                    libererItem(tmp);
                }
                
                if(noeud->suivant != NULL) // On continue à parcourir l'arbre
                {
                    minmax(noeud->suivant, meilleurCoup, meilleurScore, profondeur);
                }
                else // Si on est arrivé à la fin de l'arbre, on appelle la fonction minmax pour arriver dans le cas terminal
                {
                    minmax(noeud, meilleurCoup, meilleurScore, profondeur);
                }
            }
            else
            {
                // Si on est à une profondeur inférieure à la profondeur maximale on est donc dans le cas ou le score est inférieur à -20
                // On va donc remonter l'arbre
                printf("Score est inferieur a -20\n");
                if(noeud->suivant != NULL)
                {
                    minmax(noeud->suivant, meilleurCoup, meilleurScore, profondeur);
                }
                else
                {
                    if(noeud->profondeur != 1)
                    {
                        item * tmp = noeud;
                        noeud = noeud->parent;
                        libererItem(tmp);
                    }

                    while(noeud->suivant == NULL && noeud->profondeur != 1)
                    {
                        noeud = noeud->parent;
                    }
                    
                    if(noeud->suivant != NULL) // On continue à parcourir l'arbre
                    {
                        minmax(noeud->suivant, meilleurCoup, meilleurScore, profondeur);
                    }
                    else // Si on est arrivé à la fin de l'arbre, on appelle la fonction minmax pour arriver dans le cas terminal
                    {
                        minmax(noeud, meilleurCoup, meilleurScore, profondeur);
                    }
                }
            }
        }
    }
}

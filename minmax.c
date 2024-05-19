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

int calculScore(char ** tableau, int scoreParent)
{
    int score = 0;
    for(int i=0; i<tailleTableau; i=i+1)
    {
        for(int j=0; j<tailleTableau; j=j+1)
        {
            if(tableau[i][j]/10 == COULEUR_IA)
            {
                if(tableau[i][j]%10 == 1) // Pion
                {
                    score = score + 1;
                }
                else if(tableau[i][j]%10 == 2) // Cavalier
                {
                    score = score + 3;
                }
                else if(tableau[i][j]%10 == 3) // Fou
                {
                    score = score + 3;
                }
                else if(tableau[i][j]%10 == 4) // Tour
                {
                    score = score + 5;
                }
                else if(tableau[i][j]%10 == 5) // Dame
                {
                    score = score + 9;
                }

                if (i == 3 || i == 4 || j == 3 || j == 4) // Cases centrales
                { 
                    score = score + 0.5;
                }

            }
            if(tableau[i][j]/10 == 3 - COULEUR_IA)
            {
                if(tableau[i][j]%10 == 1) // Pion
                {
                    score = score - 1;
                }
                else if(tableau[i][j]%10 == 2) // Cavalier
                {
                    score = score - 3;
                }
                else if(tableau[i][j]%10 == 3) // Fou
                {
                    score = score - 3;
                }
                else if(tableau[i][j]%10 == 4) // Tour
                {
                    score = score - 5;
                }
                else if(tableau[i][j]%10 == 5) // Dame
                {
                    score = score - 9;
                }

                if (i == 3 || i == 4 || j == 3 || j == 4) // Cases centrales
                { 
                    score = score - 0.5;
                }
            }
        }
    }
    if(estEchecMat(tableau, COULEUR_IA))
    {
        score = score - 100;
    }

    if(estEchecMat(tableau, 3 - COULEUR_IA))
    {
        score = score + 100;
    }

    score = scoreParent + score;

    return score;
}

liste * generationCoups(item * noeud, int couleur)
{
    liste * coups = creerListe();
    item * coup = NULL;
    char ** tableau = copieTableau(noeud->tableau);
    int score;
    int m = 0;

    int meillieursScores[6]= {-1000,-1000,-1000,-1000,-1000,-1000};
    char *** meillieursCoups = malloc(6*sizeof(char **));
    meillieursCoups[0] = NULL;
    meillieursCoups[1] = NULL;
    meillieursCoups[2] = NULL;
    meillieursCoups[3] = NULL;
    meillieursCoups[4] = NULL;
    meillieursCoups[5] = NULL;

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
            if(tableau[i][j]/10 == couleur)
            {
                // On parcourt le tableau pour trouver les cases où la pièce peut se déplacer
                for(int k=0; k<tailleTableau; k=k+1) // k = ligne de la case
                {
                    for(int l=0; l<tailleTableau; l=l+1) // l = colonne de la case
                    {
                        // Si le déplacement est valide
                        if(deplacementValide(tableau, i, j, k, l))
                        {
                            deplacement(tableau, i, j, k, l);
                            score = calculScore(tableau, noeud->score);

                            if(meillieursScores[0] < score)
                            {
                                meillieursCoups[0] = copieTableau(tableau);
                                meillieursScores[0] = score;
                            }
                            else if(meillieursScores[1] < score || meillieursScores[0] == meillieursScores[1])
                            {
                                meillieursCoups[1] = copieTableau(tableau);
                                meillieursScores[1] = score;
                            }
                            else if(meillieursScores[2] < score || meillieursScores[1] == meillieursScores[2])
                            {
                                meillieursCoups[2] = copieTableau(tableau);
                                meillieursScores[2] = score;
                            }
                            else if(meillieursScores[3] < score || meillieursScores[2] == meillieursScores[3])
                            {
                                meillieursCoups[3] = copieTableau(tableau);
                                meillieursScores[3] = score;
                            }
                            else if(meillieursScores[4] < score || meillieursScores[3] == meillieursScores[4])
                            {
                                meillieursCoups[4] = copieTableau(tableau);
                                meillieursScores[4] = score;
                            }
                            else if(meillieursScores[5] < score || meillieursScores[4] == meillieursScores[5])
                            {
                                meillieursCoups[5] = copieTableau(tableau);
                                meillieursScores[5] = score;
                            }

                            while(meillieursCoups[m] == NULL)
                            {
                                printf("m = %d\n", m);
                                afficherTableau(meillieursCoups[m]);
                                coup = creerItem();
                                coup->tableau = copieTableau(meillieursCoups[m]);
                                coup->profondeur = noeud->profondeur + 1;
                                coup->score = meillieursScores[m];
                                coup->taille = tailleTableau;
                                coup->parent = noeud;
                                ajouterDernier(coups, coup);
                                m=m+1;
                                printf("Ajouté coup\n");
                            }
                        }
                    }
                }
            }
        }
    }
    return coups;
}

char ** remonterArbre(item * noeud)
{
    item * temp = noeud;
    char ** tmpTableau;
    while(temp->profondeur != 1)
    {
        temp = temp->parent;
    }
    tmpTableau = copieTableau(temp->tableau);

    return tmpTableau;
}

char ** minmax(item * noeud, char ** meilleurCoup, int meilleurScore)
{  
    int couleur;
   
    // Cas Terminal, on a fini de parcourir l'arbre
    if(noeud->suivant == NULL  && noeud->profondeur == 1)
    {
        // Si c'est le seul coup possible
        if(meilleurCoup == NULL) 
        {
            meilleurCoup = copieTableau(noeud->tableau);
        }

        // On libère la dernière branche de l'arbre
        while(noeud->precedent != NULL)
        {
            noeud = noeud->precedent;
            libererItem(noeud->suivant);
        }

        // On libère le dernier noeud
        libererItem(noeud);

        return meilleurCoup;
    }
    else
    {
        // Si on est à une profondeur inférieure à la profondeur maximale ou si le score est supérieur à -20
        // On génère les coups suivants
        if(noeud->profondeur < PROFONDEUR && noeud->score > -20)
        {
            // Déterminer la couleur des coups à générer
            if(noeud->profondeur%2 == 0)
            {
                couleur = COULEUR_IA;
            }
            else
            {
                couleur = 3 - COULEUR_IA;
            }

            // On génère les coups à partir du noeud actuel
            liste * coups = generationCoups(noeud, couleur);

            // On se place sur le premier coup généré
            noeud = coups->premier;

            // On libère la liste des coups 
            //Car plus utile une fois les coups générés (il faudrait trouver un autre moyen que les listes pour générer les coups)
            free(coups);

            // On appelle la fonction minmax pour le premier coup généré
            minmax(noeud, meilleurCoup, meilleurScore);
        }
        else
        {
            // Si on est à la profondeur maximale
            if(noeud->profondeur == PROFONDEUR)
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

                    // On libère la mémoire du noeud précédent pour liberer la brancahe de l'arbre
                    libererItem(noeud->precedent); 
                }

                // On remonte l'arbre en liberant le "fils" du noeud actuel
                // tmp car on a pas de lien avec le noeud "fils" une fois qu'on est au parent
                item * temp = noeud;
                noeud = noeud->parent;
                libererItem(temp);
                
                // On remonte l'arbre tant que le suivant est null / tant qu'on est à la fin de la branche de l'arbre
                // Si on est à la profondeur 1, on est remonter en haut de l'arbre, on arrête de remonter
                while(noeud->suivant == NULL && noeud->profondeur != 1)
                {
                    // On libère la branche de l'arbre
                    while(noeud->precedent == NULL)
                    {
                        libererItem(noeud->suivant);
                    } 

                    // On remonte l'arbre en liberant le "fils" du noeud actuel
                    // tmp car on a pas de lien avec le noeud "fils" une fois qu'on est au parent
                    item * temp = noeud;
                    noeud = noeud->parent;
                    libererItem(temp);
                }
                
                // On continue à parcourir l'arbre
                if(noeud->suivant != NULL) 
                {
                    minmax(noeud->suivant, meilleurCoup, meilleurScore);
                }
                else // On a fini de parcourir l'arbre, on appelle la fonction minmax pour arriver dans le cas terminal
                {
                    minmax(noeud, meilleurCoup, meilleurScore);
                }
            }
            else
            {
                // Si on est à une profondeur inférieure à la profondeur maximale on est donc dans le cas ou le score est inférieur à -20

                // Si on a pas fini de parcourir la branche de l'arbre
                if(noeud->suivant != NULL)
                {
                    minmax(noeud->suivant, meilleurCoup, meilleurScore);
                }
                else // Si on a fini de parcourir la branche de l'arbre
                {
                     // Si le score du noeud est supérieur au meilleur score
                     // Dans le cas ou c'est le seul coup possible
                    if(noeud->score > meilleurScore)
                    {
                        meilleurScore = noeud->score;
                        meilleurCoup = remonterArbre(noeud);
                    }

                    // Si on est à la profondeur 1, on est remonter en haut de l'arbre, on arrête de remonter
                    if(noeud->profondeur != 1)
                    {
                        item * temp = noeud;
                        noeud = noeud->parent;
                        libererItem(temp);
                    }

                    // On remonte l'arbre tant que le suivant est null / tant qu'on est à la fin de la branche de l'arbre
                    // Si on est à la profondeur 1, on est remonter en haut de l'arbre, on arrête de remonter
                    while(noeud->suivant == NULL && noeud->profondeur != 1)
                    {
                        // On libère la branche de l'arbre
                        while(noeud->precedent == NULL)
                        {
                            libererItem(noeud->suivant);
                        } 

                        // On remonte l'arbre en liberant le "fils" du noeud actuel
                        // tmp car on a pas de lien avec le noeud "fils" une fois qu'on est au parent
                        item * temp = noeud;
                        noeud = noeud->parent;
                        libererItem(temp);
                    }
                    
                    // On continue à parcourir l'arbre
                    if(noeud->suivant != NULL) 
                    {
                        noeud = noeud->suivant;
                        libererItem(noeud->precedent);
                        minmax(noeud, meilleurCoup, meilleurScore);
                    }
                    else // Si on est arrivé à la fin de l'arbre, on appelle la fonction minmax pour arriver dans le cas terminal
                    {
                        minmax(noeud, meilleurCoup, meilleurScore);
                    }
                }
            }
        }
    }
}

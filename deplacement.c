#include "deplacement.h"

// Détermine si un déplacement d'un pion est valide avec ses coordonnées X et Y initiales et finales
int positionValidePion(int ** tableau, int initialX, int initialY, int finalX, int finalY)
{
    // Pion blanc
    if(tableau[initialX][initialY]/10 == 1)
    {
        // Si une pièce allié est présente sur la case finale
        if(tableau[finalX][finalY]/10 == 1)
        {
            return 0;
        }

        // Si le pion avance de 2 cases
        if(finalY == initialY + 2 && finalX == initialX)
        {
            // Si le pion n'a pas encore bougé
            if(initialY != 1)
            {
                return 0;
            }
            
            // Si une pièce est présente sur le chemin
            if(tableau[initialX][initialY + 1] != 0)
            {
                return 0;
            }
            return 1;
        }
        
        // Si le pion avance de 1 case
        if(finalY == initialY + 1 && finalX == initialX)
        {
            // Si une pièce est présente sur la case finale
            if(tableau[finalX][finalY] == 0)
            {
                return 1;
            }
        }
        
        // Si le pion mange une pièce
        if(abs(finalX - initialX) == 1 && finalY == initialY + 1)
        {
            // Si une pièce est présente sur la case finale
            if(tableau[finalX][finalY] != 0)
            {
                return 1;
            }
        }
    }

    // Pion noir
    if(tableau[initialX][initialY]/10 == 2)
    {
        // Si une pièce allié est présente sur la case finale
        if(tableau[finalX][finalY]/10 == 2)
        {
            return 0;
        }

        // Si le pion avance de 2 cases
        if(finalY == initialY - 2 && finalX == initialX)
        {
            // Si le pion n'a pas encore bougé
            if(initialY != 6)
            {
                return 0;
            }
            
            // Si une pièce est présente sur le chemin
            if(tableau[initialX][initialY - 1] != 0)
            {
                return 0;
            }
            return 1;
        }
        
        // Si le pion avance de 1 case
        if(finalY == initialY - 1 && finalX == initialX)
        {
            // Si une pièce est présente sur la case finale
            if(tableau[finalX][finalY] == 0)
            {
                return 1;
            }
        }
        
        // Si le pion mange une pièce
        if(abs(finalX - initialX) == 1 && finalY == initialY - 1)
        {
            // Si une pièce est présente sur la case finale
            if(tableau[finalX][finalY] != 0)
            {
                return 1;
            }
        }

    }

    return 0;
}

// Détermine si un déplacement d'un fou est valide avec ses coordonnées X et Y initiales et finales
int positionValideFou(int ** tableau, int initialX, int initialY, int finalX, int finalY)
{
    // Déplacement en diagonale
    if(abs(finalX - initialX) == abs(finalY - initialY))
    {
        // Si une pièce allié est présente sur la case finale
        if(tableau[finalX][finalY]/10 == tableau[initialX][initialY]/10)
        {
            return 0;
        }

        // Déplacement en diagonale haut gauche
        if(finalX < initialX && finalY < initialY)
        {
            for(int i=1; i<abs(finalX - initialX); i=i+1)
            {
                // Si une pièce est présente sur le chemin
                if(tableau[initialX - i][initialY - i] != 0)
                {
                    return 0;
                }
            }
            return 1;
        }

        // Déplacement en diagonale haut droite
        if(finalX > initialX && finalY < initialY)
        {
            for(int i=1; i<abs(finalX - initialX); i=i+1)
            {
                // Si une pièce est présente sur le chemin
                if(tableau[initialX + i][initialY - i] != 0)
                {
                    return 0;
                }
            }
            return 1;
        }

        // Déplacement en diagonale bas gauche
        if(finalX < initialX && finalY > initialY)
        {
            for(int i=1; i<abs(finalX - initialX); i=i+1)
            {
                // Si une pièce est présente sur le chemin
                if(tableau[initialX - i][initialY + i] != 0)
                {
                    return 0;
                }
            }
            return 1;
        }

        // Déplacement en diagonale bas droite
        if(finalX > initialX && finalY > initialY)
        {
            for(int i=1; i<abs(finalX - initialX); i=i+1)
            {
                // Si une pièce est présente sur le chemin
                if(tableau[initialX + i][initialY + i] != 0)
                {
                    return 0;
                }
            }
            return 1;
        }
    }

    return 0;
}

// Détermine si un déplacement d'un cavalier est valide avec ses coordonnées X et Y initiales et finales
int positionValideCavalier(int ** tableau, int initialX, int initialY, int finalX, int finalY)
{
    // Déplacement en L
    if((abs(finalX - initialX) == 2 && abs(finalY - initialY) == 1) || (abs(finalX - initialX) == 1 && abs(finalY - initialY) == 2))
    {
        // Si une pièce allié est présente sur la case finale
        if(tableau[finalX][finalY]/10 == tableau[initialX][initialY]/10)
        {
            return 0;
        }

        return 1;
    }

    return 0;
}

// Détermine si un déplacement d'une tour est valide avec ses coordonnées X et Y initiales et finales
int positionValideTour(int ** tableau, int initialX, int initialY, int finalX, int finalY)
{
    // Si une pièce allié est présente sur la case finale
    if(tableau[finalX][finalY]/10 == tableau[initialX][initialY]/10)
    {
        return 0;
    }

    // Déplacement vertical
    if(initialX == finalX)
    {
        // Déplacement vers le haut
        if(finalY < initialY)
        {
            for(int i=1; i<abs(finalY - initialY); i=i+1)
            {
                // Si une pièce est présente sur le chemin
                if(tableau[initialX][initialY - i] != 0)
                {
                    return 0;
                }
            }
            return 1;
        }

        // Déplacement vers le bas
        if(finalY > initialY)
        {
            for(int i=1; i<abs(finalY - initialY); i=i+1)
            {
                // Si une pièce est présente sur le chemin
                if(tableau[initialX][initialY + i] != 0)
                {
                    return 0;
                }
            }
            return 1;
        }
    }

    // Déplacement horizontal
    if(initialY == finalY)
    {
        // Déplacement vers la gauche
        if(finalX < initialX)
        {
            for(int i=1; i<abs(finalX - initialX); i=i+1)
            {
                // Si une pièce est présente sur le chemin
                if(tableau[initialX - i][initialY] != 0)
                {
                    return 0;
                }
            }
            return 1;
        }

        // Déplacement vers la droite
        if(finalX > initialX)
        {
            for(int i=1; i<abs(finalX - initialX); i=i+1)
            {
                // Si une pièce est présente sur le chemin
                if(tableau[initialX + i][initialY] != 0)
                {
                    return 0;
                }
            }
            return 1;
        }
    }
   
   return 0;
}

// Détermine si un déplacement d'une dame est valide avec ses coordonnées X et Y initiales et finales
int positionValideDame(int ** tableau, int initialX, int initialY, int finalX, int finalY)
{
    // Si une pièce allié est présente sur la case finale
    if(tableau[finalX][finalY]/10 == tableau[initialX][initialY]/10)
    {
        return 0;
    }

    // Déplacement vertical
    if(initialX == finalX)
    {
        // Déplacement vers le haut
        if(finalY < initialY)
        {
            for(int i=1; i<abs(finalY - initialY); i=i+1)
            {
                // Si une pièce est présente sur le chemin
                if(tableau[initialX][initialY - i] != 0)
                {
                    return 0;
                }
            }
            return 1;
        }

        // Déplacement vers le bas
        if(finalY > initialY)
        {
            for(int i=1; i<abs(finalY - initialY); i=i+1)
            {
                // Si une pièce est présente sur le chemin
                if(tableau[initialX][initialY + i] != 0)
                {
                    return 0;
                }
            }
            return 1;
        }
    }

    // Déplacement horizontal
    if(initialY == finalY)
    {
        // Déplacement vers la gauche
        if(finalX < initialX)
        {
            for(int i=1; i<abs(finalX - initialX); i=i+1)
            {
                // Si une pièce est présente sur le chemin
                if(tableau[initialX - i][initialY] != 0)
                {
                    return 0;
                }
            }
            return 1;
        }

        // Déplacement vers la droite
        if(finalX > initialX)
        {
            for(int i=1; i<abs(finalX - initialX); i=i+1)
            {
                // Si une pièce est présente sur le chemin
                if(tableau[initialX + i][initialY] != 0)
                {
                    return 0;
                }
            }
            return 1;
        }
    }

    // Déplacement en diagonale
    if(abs(finalX - initialX) == abs(finalY - initialY))
    {
        // Déplacement en diagonale haut gauche
        if(finalX < initialX && finalY < initialY)
        {
            for(int i=1; i<abs(finalX - initialX); i=i+1)
            {
                // Si une pièce est présente sur le chemin
                if(tableau[initialX - i][initialY - i] != 0)
                {
                    return 0;
                }
            }
            return 1;
        }

        // Déplacement en diagonale haut droite
        if(finalX > initialX && finalY < initialY)
        {
            for(int i=1; i<abs(finalX - initialX); i=i+1)
            {
                // Si une pièce est présente sur le chemin
                if(tableau[initialX + i][initialY - i] != 0)
                {
                    return 0;
                }
            }
            return 1;
        }

        // Déplacement en diagonale bas gauche
        if(finalX < initialX && finalY > initialY)
        {
            for(int i=1; i<abs(finalX - initialX); i=i+1)
            {
                // Si une pièce est présente sur le chemin
                if(tableau[initialX - i][initialY + i] != 0)
                {
                    return 0;
                }
            }
            return 1;
        }

        // Déplacement en diagonale bas droite
        if(finalX > initialX && finalY > initialY)
        {
            for(int i=1; i<abs(finalX - initialX); i=i+1)
            {
                // Si une pièce est présente sur le chemin
                if(tableau[initialX + i][initialY + i] != 0)
                {
                    return 0;
                }
            }
            return 1;
        }
    }

    return 0;
}

// Détermine si un déplacement d'un roi est valide avec ses coordonnées X et Y initiales et finales
int positionValideRoi(int ** tableau, int initialX, int initialY, int finalX, int finalY)
{
    // Si une pièce allié est présente sur la case finale
    if(tableau[finalX][finalY]/10 == tableau[initialX][initialY]/10)
    {
        return 0;
    }

    // Déplacement vertical
    if(abs(finalX - initialX) == 1 && abs(finalY - initialY) == 0)
    {
        return 1;
    }

    // Déplacement horizontal
    if(abs(finalX - initialX) == 0 && abs(finalY - initialY) == 1)
    {
        return 1;
    }

    // Déplacement en diagonale
    if(abs(finalX - initialX) == 1 && abs(finalY - initialY) == 1)
    {
        return 1;
    }

    return 0;
}
    
// Détermine si un déplacement est valide avec ses coordonnées X et Y initiales et finales
int positionValide(int ** tableau, int initialX, int initialY, int finalX, int finalY)
{
    // Si la case d'arrivée est hors du tableau
    if(finalX < 0 || finalX >= tailleTableau || finalY < 0 || finalY >= tailleTableau)
    {
        printf("Erreur : case d'arrivee hors du tableau\n");
        return 0;
    }
    // Si la case de depart est la meme que la case d'arrivee
    if(initialX == finalX && initialY == finalY)
    {
        printf("InitialX : %d, InitialY : %d, FinalX : %d, FinalY : %d\n", initialX, initialY, finalX, finalY);
        printf("Erreur : case de depart identique a la case d'arrivee\n");
        return 0;
    }

    // Si la case de départ est vide
    if(tableau[initialX][initialY]%10 == 0)
    {
        printf("Erreur : case de depart vide\n");
        return 0;
    }
    
    // Cas du pion
    if(tableau[initialX][initialY]%10 == 1)
    {
        return positionValidePion(tableau, initialX, initialY, finalX, finalY);
    }

    // Cas du fou
    if(tableau[initialX][initialY]%10 == 2)
    {
        return positionValideFou(tableau, initialX, initialY, finalX, finalY);
    }

    // Cas du cavalier
    if(tableau[initialX][initialY]%10 == 3)
    {
        return positionValideCavalier(tableau, initialX, initialY, finalX, finalY);
    }

    // Cas de la tour
    if(tableau[initialX][initialY]%10 == 4)
    {
        return positionValideTour(tableau, initialX, initialY, finalX, finalY);
    }

    // Cas de la dame
    if(tableau[initialX][initialY]%10 == 5)
    {
        return positionValideDame(tableau, initialX, initialY, finalX, finalY);
    }

    // Cas du roi
    if(tableau[initialX][initialY]%10 == 6)
    {
        return positionValideRoi(tableau, initialX, initialY, finalX, finalY);
    }

    printf("Erreur : déplacement non pris en compte\n");
    return 0;
}

// Détermine si le roi est en échec pour une couleur donnée
int estEchec(int ** tableau, int couleur)
{
    int xRoi, yRoi;

    // Parcours des cases du tableau
    for(int i=0; i<tailleTableau; i=i+1)
    {
        for(int j=0; j<tailleTableau; j=j+1)
        {
            // Si le roi est présent
            if(tableau[i][j] == couleur*10 + 6)
            {
                xRoi = i;
                yRoi = j;
            }
        }
    }

    // Parcours des cases du tableau
    for(int i=0; i<tailleTableau; i=i+1)
    {
        for(int j=0; j<tailleTableau; j=j+1)
        {
            // Si une pièce ennemie est présente
            if(tableau[i][j]/10 != couleur && tableau[i][j] != 0)
            {
                // Si le déplacement est valide
                if(positionValide(tableau, i, j, xRoi, yRoi))
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

// Détermine si un déplacement est valide avec ses coordonnées X et Y initiales et finales et si le roi n'est pas en échec
int deplacementValide(int ** tableau, int initialX, int initialY, int finalX, int finalY)
{
    int ** temporaire;
    // Si le déplacement est valide
    if(positionValide(tableau, initialX, initialY, finalX, finalY))
    {
        // Déplacement de la pièce
        temporaire = copieTableau(tableau);
        deplacement(temporaire, initialX, initialY, finalX, finalY);

        printf("estEchec : %d\n", estEchec(temporaire, tableau[initialX][initialY]/10));

        // Si le roi est en échec une fois le déplacement effectué
        if(estEchec(temporaire, tableau[initialX][initialY]/10))
        {
            free(temporaire);
            return 0;
        }

        free(temporaire);
        return 1;
    }
    return 0;
}

//Détermine si le roi est echet et mat pour une couleur donnée
int estEchecMat(int ** tableau, int couleur)
{
    // Parcours des cases du tableau
    for(int i=0; i<tailleTableau; i=i+1)
    {
        for(int j=0; j<tailleTableau; j=j+1)
        {
            // Si une pièce alliée est présente
            if(tableau[i][j]/10 == couleur)
            {
                // Parcours des cases du tableau
                for(int k=0; k<tailleTableau; k=k+1)
                {
                    for(int l=0; l<tailleTableau; l=l+1)
                    {
                        // Si le déplacement est valide
                        if(deplacementValide(tableau, i, j, k, l))
                        {
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf("Echec et mat\n");

    return 1;
}

void deplacement(int **tableau, int initialX, int initialY, int finalX, int finalY)
{
    tableau[finalX][finalY] = tableau[initialX][initialY];
    tableau[initialX][initialY] = 0;
}

#include "minmax.h"
#include <limits.h> 

int max(int a, int b) {
    if(a>b)
    return a;
    else{
        return b;

    }
}
int min(int a, int b) {
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}

int calculScore(item * noeud, int couleur)
{
    int score = 0;
    for(int i=0; i<tailleTableau; i=i+1)
    {
        for(int j=0; j<tailleTableau; j=j+1)
        {
            if(noeud->tableau[i][j]/10 == couleur)
            {
                score = score + noeud->tableau[i][j]%10;
            }
            else
            {
                score = score - noeud->tableau[i][j]%10;
            }
        }
    }
    if(estEchecMat(noeud->tableau, couleur))
    {
        score = score - 20;
    }
    noeud->score = noeud->score + score;
    return noeud->score; 

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



void generationCoupsRec(item *noeud, liste *coups, int couleur, int profondeur) {
    if (profondeur == 4 || estEchecMat(noeud->tableau, couleur)) {
        return;
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < tailleTableau; j++) {
            if (noeud->tableau[i][j] / 10 == couleur) {
                for (int k = 0; k < tailleTableau; k++) {
                    for (int l = 0; l < tailleTableau; l++) {
                        if (deplacementValide(noeud->tableau, i, j, k, l)) {
                            item *coup = creerItem();
                            coup->tableau = copieTableau(noeud->tableau);
                            deplacement(coup->tableau, i, j, k, l);
                            coup->profondeur = noeud->profondeur + 1;
                            coup->parent = noeud;
                            calculScore(coup, couleur);
                            ajouterDernier(coups, coup);

                            // Appel récursif
                            generationCoupsRec(coup, coups, couleur, profondeur + 1);
                        }
                    }
                }
            }
        }
    }
}

// Fonction wrapper pour initialiser la recherche
liste *generationCoups2(item *noeud, int couleur) {
    liste *coups = creerListe();
    generationCoupsRec(noeud, coups, couleur, noeud->profondeur);
    return coups;
}
int minimax(item *noeud, int profondeur, int couleur, int maximizingPlayer) {
    if (profondeur == 0 || estEchecMat(noeud->tableau, couleur)) {
        return calculScore(noeud, couleur);
    }

    int meilleurScore = maximizingPlayer ? INT_MIN : INT_MAX;

    liste *coups = generationCoups(noeud, couleur);
    for (item *coup = coups->premier; coup != NULL; coup = coup->suivant) {
        int score = minimax(coup, profondeur - 1, 3 - couleur, !maximizingPlayer);
        if (maximizingPlayer) {
            meilleurScore = max(meilleurScore, score);
        } else {
            meilleurScore = min(meilleurScore, score);
        }
    }
    return meilleurScore;
}

item *trouverMeilleurCoup(item *etatInitial, int couleur) {
    int meilleurScore = INT_MIN;
    item *meilleurCoup = NULL;

    liste *coups = generationCoups(etatInitial, couleur);
    for (item *coup = coups->premier; coup != NULL; coup = coup->suivant) {
        int score = minimax(coup, 4 - 1, 3 - couleur, 0);  // 0 indique le joueur minimisant après ce coup
        if (score > meilleurScore) {
            meilleurScore = score;
            meilleurCoup = coup;
        }
    }
    return meilleurCoup;
}

void affichetouslescoupsRec(item * noeud){
    if(noeud->profondeur == 4){
        afficherTableau(noeud->tableau);
        return;
    }
    else {
        afficherTableau(noeud->tableau);
        affichetouslescoupsRec(noeud->suivant);
    
    }
}
void affichetouslescoups(liste * coups){
    item * courant = coups->premier;
    //affichetouslescoupsRec(courant);
    while(courant->profondeur != 4){
        afficherTableau(courant->tableau);
        courant = courant->suivant;
    }


}

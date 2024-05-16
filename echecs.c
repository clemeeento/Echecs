#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "item.h"
#include "liste.h"
#include "echiquier.h"
#include "deplacement.h"
#include "minmax.h"
#include "graphique.h"

int main()
{
    int ** tableau = initialisationPartie();
    test(tableau);                                      
    return 0;
}

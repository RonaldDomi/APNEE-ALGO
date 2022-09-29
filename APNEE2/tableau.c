#include <stdlib.h>
#include <stdio.h>
#include "tableau.h"

void init_tab(tableau *t)
{
    t->taille = 0;
    t->tab = malloc(10000);
}

void empiler(tableau *t, char c){
    t->tab[t->taille] = c;
    t->taille++;
}

char depiler(tableau *t){
    t->taille--;
    return t->tab[t->taille+1];
}

int est_vide(tableau t){
    return t.taille == 0
}

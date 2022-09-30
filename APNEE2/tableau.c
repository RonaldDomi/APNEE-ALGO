#include <stdlib.h>
#include <stdio.h>
#include "tableau.h"

void init_tab(tableau *t)
{
    t->taille = 0;
    t->tab = malloc(1000000);
}

void empiler(tableau *t, char c){
    t->tab[t->taille] = c;
    t->taille++;
}

char depiler(tableau *t){
    t->taille--;
    return t->tab[t->taille];
}


int est_vide(tableau t){
    return t.taille == 0;
}

void afficher_tab(tableau t){
    printf("\n");
    for (int i = 0; i < t.taille; i++)
    {
        printf(" t[%d] : %c, ", i, t.tab[i]);
    }
    printf("\n");
}
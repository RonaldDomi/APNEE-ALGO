#ifndef _TABLEAU_H
#define _TABLEAU_H

typedef struct tableau
{
    char *tab;
    int taille;
} tableau;

void init_tab(tableau *t);

void empiler(tableau *t, char c);

char depiler(tableau *t);

int est_vide(tableau t);

void afficher_tab(tableau t);


#endif
#include <stdlib.h>
#include <stdio.h>
#include "tableau.h"

void parenthese_correct(FILE* file, int nbr_min){
    srand(time(NULL));
    tableau t;
    init_tab(&t);
    char car, tmp;
    int rd, rd2, taille_elem = 0;
    while (!est_vide(t) || taille_elem < nbr_min)
    {
        if(!est_vide(t)) rd = rand() % 2;
        //si la pile est vide on peut pas avoir de parenthése 
        //fermante donc on force parenthese ouvrante
        else rd = 0;
        switch (rd)
        {
        case 0:
        /*cas parenthese ouvrante*/
            rd2 = rand()%3;
            switch (rd2)
            {
            case 0:
                car = '(';
                break;
            case 1:
                car = '[';
                break;
            case 2:
                car = '{';
                break;    
            }
            putc(car, file);
            empiler(&t, car);
            break;
        case 1:
            /* code parenthese fermante*/
            tmp = depiler(&t);
            switch(tmp)
            {
                case '(':
                    car = ')';
                    break;
                case '{':
                    car = '}';
                    break;
                case '[':
                    car = ']';
                    break;
            }
            putc(car, file);
            break; 
        }
        taille_elem++;
    }
    putc('\n', file);
}

int main(int argc, char **argv){
    if (argc != 3)
    {
        printf("\nNombre dargument incorrect\n");
        printf("./generation file nbr_min_element\n");
        return 1;
    }
    FILE* file = fopen(argv[1], "w");
    int nbr_min = atoi(argv[2]);
    parenthese_correct(file, nbr_min);
    fclose(file);
    return 0;
}
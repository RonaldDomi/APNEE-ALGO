#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"

int correspond(char a, char b){
  switch (a)
  {
  case '(':
    return b == ')';
  case '{':
    return b == '}';
  case '[':
    return b == ']';    
  default:
    break;
  }
  return 0;
}

int OracleParenthesage(FILE * input, int reponse) {

  tableau t;
  init_tab(&t);
  int tmp;
  int rep = 1;
  while ((tmp = getc(input)) != EOF)
  {
    if (tmp == '(' || tmp == '[' || tmp == '{')
    {
      empiler(&t, tmp);
    }
    if (tmp == ')' || tmp == ']' || tmp == '}')
    {
      if (est_vide(t) || !correspond(depiler(&t), tmp))
      {
        rep = 0;
      }
      
    }
  }
  if(!est_vide(t)) rep = 0;
  return reponse==rep;
}

int main(int argc, char * argv[]) {
  FILE * input;
  FILE * output;
  char output_string[25];
  char *s;
  /* Valeur booleenne de la sortie (vrai pour "Bon parenthesage") */
  int output_value;

  if (argc < 3) {
    printf("Usage: %s <input_file> <output_file>\n", argv[0]);
    return 1;
  }

  input = fopen(argv[1], "r");
  if (input == NULL) {
    fprintf(stderr, "Erreur lors de l'ouverture du fichier %s\n", argv[1]);
    return 1;
  }

  output = fopen(argv[2], "r");
  if (output == NULL) {
    fprintf(stderr, "Erreur lors de l'ouverture du fichier %s\n", argv[2]);
    fclose(input);
    return 1;
  }

  s = fgets(output_string, 25, output);
  if (s==NULL) {
    fprintf(stderr, "Erreur lors de la lecture dans le fichier %s\n", argv[2]);
    fclose(input);
    fclose(output);
    return 1;
  }
  
  if (strcmp(output_string,"Bon parenthesage\n") == 0) {
    output_value = 1;
  } else if (strcmp(output_string,"Mauvais parenthesage\n") == 0) {
    output_value = 0;
  } else {
    printf("ERREUR\n");
    fclose(input);
    fclose(output);
    return 1;
  }

  if (OracleParenthesage(input,output_value)) {
    printf("OK\n");
    fclose(input);
    fclose(output);
    return 0;
  } else {
    printf("ERREUR\n");
    fclose(input);
    fclose(output);
    return 1;
  }
}

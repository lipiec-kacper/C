/*
  * Implémentez la fonction split, qui prend comme argument un string et un indice dans ce string. Cette fonction renvoie un tableau composé de deux sous-string, le premier contenant les caractères allant de 0 à l’indice non compris dans le string d'entrée, et le deuxième composé du reste du string.
  * Par exemple pour le string :

  *"abcdefghijklmnopqrstuvwxyz"

  *Le résultat de la fonction split avec ce string et l’indice 5 est :

  *[ "abcde", "fghijklmnopqrstuvwxyz" ]

  *Pour cette question, les seules fonctions de la librairie standard que vous êtes autorisés à utiliser sont malloc(3) et strlen(3)
*/


//Insérez ici le corps de la fonction split dont les spécifications vous sont données ci-dessous :


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * pre:
 * - str est un null-terminated string non null
 * - 0 <= n <= strlen(str)
 * post:
 * - renvoie un tableau de string contenant deux null-terminated strings
 * - le premier contient les caractères aux positions 0..n-1 dans str
 * - le deuxième contient le reste des caractères de str
 * - renvoie NULL en cas d’erreur
 */
char** split(char* str, int n) {

  if(str == NULL || n < 0){
    return NULL;
  }

  int str_lenght = strlen(str);
  if(n > str_lenght){
    return NULL;
  }

  int soustraction = str_lenght - n;

  char **array = malloc(2 * sizeof(char*));
  if(array == NULL){
    return NULL;
  }
  
  array[0] = malloc((n + 1) * sizeof(char));
  if(array[0] == NULL){
    free(array);
    return NULL;
  }
  array[1] = malloc(soustraction + 1 * sizeof(char));
  if(array[1] == NULL){
    free(array);
    return NULL;
  }

  for(int j = 0; j < n; j++){
    array[0][j] = str[j];
  }

  array[0][n] = '\0';

  int k = n;

  for(int n = 0; n < soustraction && k < str_lenght; n++){
    array[1][n] = str[k];
    k++;
  }

  array[1][soustraction] = '\0';

  return array;
}

//Insérez votre code de test optionnel ci-dessous. Vous pouvez utiliser printf dans cette fonction pour débugger votre programme.

int main(){
  char* string = "abcdefghijklmnopqrstuvwxyz";
  int n = 6;
  int str_lenght = strlen(string);

  char** result = split(string, n);

  for(int i = 0; i < 2; i++){
    printf("%s", result[i]);
    printf("\n");
  }

  return 0;
}

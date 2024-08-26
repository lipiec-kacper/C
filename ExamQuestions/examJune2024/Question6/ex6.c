/* Entrez la taille des tableaux : 3 */
/* Entrez les éléments du premier tableau (en ordre croissant) : 1 */
/* 3 */
/* 7 */
/* Entrez les éléments du deuxième tableau (en ordre croissant) : -2 */
/* 6 */
/* 9 */
/* Tableau fusionné (trié en ordre croissant) : -2 1 3 6 7 9 */
/**/


#include <stdio.h>
#include <stdlib.h>


/*
 * @pre tableau1!=NULL, tableau2!=NULL, n>0
 *      tableau1 et tableau2 sont des tableaux d'entiers de taille n en ordre
 *      croissant
 * @post retourne un pointeur vers un tableau de taille 2*n contenant tous les
 *       éléments des deux tableaux dans l'ordre croissant
 *       retourne NULL en cas de problème d'allocation de mémoire
 */

int* fusionnerTableaux(int *tableau1, int *tableau2, int n) {
  if(tableau1 == NULL || tableau2 == NULL){
    return NULL;
  }
  if(n <= 0){
    return NULL;
  }

  int *final_tableau = malloc((2 * n) * sizeof(int));
  int final_tab_length = (2 * n);

  if(final_tableau == NULL){
    return NULL;
  }

  for(int i = 0; i < n; i++){
    final_tableau[i] = tableau1[i];
    final_tableau[i + n] = tableau2[i];
  }

  //sort of the array

  for(int l = 0; l < final_tab_length - 1; l++){
    for(int m = 0; m < final_tab_length - 1; m++){
      if(final_tableau[m] > final_tableau[m+1]){
        int temp = final_tableau[m];
        final_tableau[m] = final_tableau[m+1];
        final_tableau[m+1] = temp;
      }
    }
  }

  return final_tableau;

}

int main(int argc, char **argv) {
  int n;
  printf("Entrez la taille des tableaux : ");
  scanf("%d", &n);
  int tableau1[n];
  int tableau2[n];
  printf("Entrez les éléments du premier tableau (en ordre croissant) : ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &tableau1[i]);
  }
  printf("Entrez les éléments du deuxième tableau (en ordre croissant) : ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &tableau2[i]);
  }
  int *tableauFusionne = fusionnerTableaux(tableau1, tableau2, n);
  if (tableauFusionne != NULL) {
    printf("Tableau fusionné (trié en ordre croissant) : ");
    for (int i = 0; i < 2 * n; i++) {
      printf("%d ", tableauFusionne[i]);
    }
    printf("\n");
    free(tableauFusionne);
  }
  return 0;
}


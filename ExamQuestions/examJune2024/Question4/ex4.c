#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fraction {
   int numerateur;
   int denominateur;
};
/*
 * @pre f1!=NULL, f2!=NULL
 * @post retourne un pointeur vers une struct fraction contenant la
 *       somme des fractions f1 et f2 (cette fraction ne doit pas être réduite)
 *       en cas de problème d'allocation de mémoire, retourne NULL
 */
struct fraction * addition(struct fraction *f1, struct fraction *f2){
  if(f1 == NULL || f2 == NULL){
    return;
  }

  struct fraction *result = malloc(2 * sizeof(int));
  if(result == NULL){
    return;
  }
  int result_nume = (f1->numerateur * f2->denominateur) + (f2->numerateur * f1->denominateur);
  int result_deno = f1->denominateur * f2->denominateur;

  result->numerateur = result_nume;
  result->denominateur = result_deno;

  return result;
}

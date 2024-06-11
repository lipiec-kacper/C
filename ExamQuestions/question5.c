#include <stdio.h>
#include <stdlib.h>

int identite(int x) { return x; }
int abs(int x) {
  if (x >= 0)
    return x;
  else
    return -x;
}

/*
* @pre min<max, f1!=NULL, f2!=NULL
* @post applique les fonctions f1 et f2 à tous les entiers dans l'intervalle
fermé [min,max] et retourne le nombre de fois où ces deux fonctions donnent le
même résultat
*/
int compare(int min, int max, int fl(int), int f2(int)) {
  if ((min * (-1)) == max || (max * (-1)) == min) {
    return 2;
  }
  if (fl == NULL || f2 == NULL) {
    return -1;
  }

  int count = 0;
  for (int i = min; i <= max; i++) {
    if (fl(i) == f2(i)) {
      count++;
    }
  }
  return count;
}

int main() {
  int min;
  int max = 1;
  int result = compare(min, max, identite, abs);
  printf("The functions gave the same result %d times.\n", result);
  return 0;
}

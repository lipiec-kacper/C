#include "stdio.h"
// L'EPL a développé un petit logiciel en C qui stocke les points de tous les
// étudiants dans un tableau contenant des structures "record" définies comme
// suit
struct record {
  char *student; // nil de l'étudiant (toujours différent de NULL)
  int n;         // nombre de cours suivis (strictement positif)
  int *points; // points obtenus pour chaque cours (les points sont toujours en
               // 0 et 20)
};

// Question1: Compter le nombre d'étudiants en échecs
/*
 * @pre n›o correspond au nombre d'étudiants dans la classe, classe!=NULL
 * @post retourne le nombre de cours en échecs pour l'ensemble des étudiants de
 * la classe
 */
int echecs(int n, struct record *classe) {
  int result = 0;
  if (n == 0) {
    return -1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < classe[i].n; j++) {
      if (classe[i].points[j] < 10) {
        printf("negative points : %d\n", classe[i].points[j]);
        result++;
      }
    }
  }
  return result;
}

int main() {
  int pointsMarie[] = {18, 10, 11};
  int pointsJean[] = {9, 7, 13, 20, 10};
  int pointsLuc[] = {10, 11, 6, 0};
  struct record classe[] = {{"Marie", 3, pointsMarie},
                            {"Jean", 5, pointsJean},
                            {"Luc", 4, pointsLuc}};

  int num_echec = echecs(3, classe);

  printf("The amount of students that failled : %d\n", num_echec);

  return 0;
}

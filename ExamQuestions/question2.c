#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * @pre -
 * @post retourne le nombre de caractères différents dans la chaine pointée par
 * str Examples: -ndiff("ABA") retourne 2 -ndiff("") retourne 0 -ndiff(NULL)
 * retourne 0 -ndiff("AabBab") retourne 4
 * */

int ndiff(char *str) {
  int result = 0;
  if (str == NULL) {
    return result = 0;
  }

  size_t strLen = strlen(str);
  if (strLen == 0) {
    return result = 0;
  }
  int *array = malloc(strLen * sizeof(int));

  int found = 0;
  int i = 0;
  array[i] = str[i];
  result = 1;

  for (int j = 1; j < strLen; j++) {
    if (str[i] != str[j]) {
      for (int k = 0; k < result; k++) {
        if (str[j] == array[k]) {
          found = 1;
        }
      }
      if (found == 0) {
        array[result++] = str[j];
      } else {
        found = 0;
      }
    }
  }
  free(array);
  return result;
}

int main() {
  char *string = NULL;
  int result = ndiff(string);
  printf("%d", result);
  return 0;
}

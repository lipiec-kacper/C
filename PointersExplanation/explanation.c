#include "stdio.h"

void printAge(int *pAge) { printf("You are %d years old\n", *pAge); }

int main() {
  int age = 21;
  int *pAge = &age;

  char *word = "Kacper";
  int wordLength = 0;
  while (*word != '\0') {
    wordLength++;
    word++;
  }

  printf("String length = %d\n", wordLength);

  printf("Address of age: %p\n", &age);
  printf("Value of age: %d\n", age);
  printf("Size of age: %lu bytes\n", sizeof(age));

  printf("Address of pAge %p\n", pAge);
  printf("Value of pAge: %d\n", *pAge);
  printf("Size of pAge: %lu bytes\n", sizeof(pAge));

  printAge(pAge);
  return 0;
}

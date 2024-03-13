#include <stdlib.h>
#include <stdio.h>
  void *calloc2(size_t nmemb, size_t size){
  //verif pour éviter le dépassement
  if(nmemb == 0 || size == 0){
    return NULL;
  }
  //Calcul de la taille totale 
  size_t totalSize = nmemb * size;
  //verif si pas de dépassement
  if(totalSize / nmemb != size){
    return NULL;
  }

  //Allocation de la mémmoire
  void *ptr = malloc(totalSize);

  //Véérification de la réussite de l'Allocation
  if(ptr == NULL){
    return NULL;
  }

  //Initialisation de la mémoire alloué à 0
  
  for(size_t i = 0; i < totalSize; ++i){
    *((char *)ptr + i) = 0;
  }

  return ptr;
}

int main() {
    // Test the calloc2 function
    size_t num_elements = 5;
    size_t element_size = sizeof(int);
    int *array = (int *)calloc2(num_elements, element_size);

    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Memory allocation successful.\n");

    // Free the allocated memory
    free(array);

    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> //Included for sleep function
void *sleepy_malloc(size_t s){
  void *ptr = NULL;
    int attempts = 0;

    // Attempt memory allocation multiple times
    while (ptr == NULL && attempts < 10) {
        ptr = malloc(s);
        if (ptr == NULL) {
            // If allocation failed, sleep for a certain period
            sleep(5);
            attempts++;
        }
    }

    return ptr;
}


int main() {
    size_t size = 1000000; // Allocate 1 MB of memory
    void *ptr = NULL;

    // Attempt to allocate memory using sleepy_malloc
    ptr = sleepy_malloc(size);

    if (ptr != NULL) {
        printf("Memory allocation successful.\n");
        free(ptr); // Free the allocated memory
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}

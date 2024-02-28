#include <stdio.h>

// int main(int argc, char **argv){
//      // Iterate through the arguments starting from the first one (index 1)
//     for (int i = 1; i < argc; i += 2) {
//         printf("%s", argv[i]); // Print the argument
//         if (i + 2 < argc) {
//             printf(" "); // Add a space if there are more arguments to print
//         }
//     }
//     printf("\n"); // Terminate the output with a new line
//     return 0;
// }


int main(int argc, char **argv){

    for (int i = 1; i < argc; i++) {
        printf("%d :%s ", i, argv[i]);
        printf("\n"); // Print the argument
    }
    printf("\n"); // Terminate the output with a new line
    return 0;
}
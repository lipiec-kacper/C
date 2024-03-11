#include <stdio.h>

struct fract_t{
    int numerator;
    int denominator;
};

void swap(struct fract_t *a, struct fract_t *b){
    
    int temp_numerator = a->numerator;
    a->numerator = b->numerator;
    b->numerator = temp_numerator;

    int temp_denominator = a->denominator;
    a->denominator = b->denominator;
    b->denominator = temp_denominator;
}


int main(){
    struct fract_t fraction1 = {3,6};
    struct fract_t fraction2 = {5, 6};

    printf("Avant l'echange:\n");
    printf("Fraction 1: %d/%d\n", fraction1.numerator, fraction1.denominator);
    printf("Fraction 2: %d/%d\n", fraction2.numerator, fraction2.denominator);

    // Appel de la fonction swap pour échanger les fractions
    swap(&fraction1, &fraction2);

    // Affichage après l'échange
    printf("\nApres l'echange:\n");
    printf("Fraction 1: %d/%d\n", fraction1.numerator, fraction1.denominator);
    printf("Fraction 2: %d/%d\n", fraction2.numerator, fraction2.denominator);

    return 0;


}

//This is for & in the main function

// In the swap function, the & operator is used to pass the addresses of the structures representing the fractions (struct fract_t) rather than passing the structures themselves. 
//This is necessary because the swap function needs to modify the values of the fractions, and passing pointers allows these modifications to be reflected outside the swap function.

// When you pass the address of a structure (&fraction1, &fraction2), you are effectively passing a pointer to that structure. 
//This pointer allows the function to access and modify the original structures directly.

// Here's why the & operator is used:

// Passing by Reference: In C, structures are typically passed by value, meaning a copy of the structure is passed to the function. 
//If you just passed fraction1 and fraction2 directly, swap would receive copies of these structures, and any modifications made to these copies within swap would not affect the original structures outside the function. 
//By passing pointers to the structures (&fraction1 and &fraction2), swap receives the addresses of the original structures, enabling it to modify them directly.
// Pointer Access: Since swap expects pointers to structures, the & operator is used to obtain the addresses of fraction1 and fraction2. This ensures that the pointers passed to swap point to the original structures.
// Efficiency: Passing pointers is often more efficient than passing entire structures, especially for large data structures, as it avoids making copies of the data.
// In summary, using the & operator to pass the addresses of the structures allows the swap function to directly modify the original structures, achieving the desired swapping behavior.

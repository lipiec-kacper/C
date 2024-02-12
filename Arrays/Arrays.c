#include <stdio.h>

//How to go through an array in different ways
//Using a for loop with indexing:

int main(){
    int array[] = {1,2,3,4,5};

    int size = sizeof(array) / sizeof(array[0]); 

    for(int i = 0; i < size; i++){
        printf("%d", array[i]);
    }

    return 0;
}


//Using for loop with pointer:

int main(){
    int array[] = {1,2,3,4,5};

    int size = sizeof(array) / sizeof(array[0]);
    int *ptr = array;
    for(int i = 0; i < size; i++){
        printf("%d", *(ptr + i));
    }

    return 0;
}


//Using while loop and pointer 

int main(){
    int array[] = {1,2,3,4,5,6,7};

    int size = sizeof(array) / sizeof(array[0]);
    int *ptr = array;

    while(ptr < array + size){
        printf("%d", *ptr);
        ptr++;
    }
    return 0;
}


//Inginious exercise:
//Write the body of :
/* tab_find

@tab : an array of int
@len : the number of int in tab
@elem : the elem looked for
@return : return the index at which elem is found, else returns -1 if not found. */
//int tab_find(int tab[], int len, int elem)

int tab_find(int tab[], int len, int elem){
    for(int i = 0; i < len; i++){
        if(tab[i] == elem){
            return i;
        }
    }
    return -1;
}
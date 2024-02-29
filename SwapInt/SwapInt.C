#include <stdio.h>


void swap(int *i, int *j){
    int temp = *i;

    *i = *j;
    *j = temp;
}

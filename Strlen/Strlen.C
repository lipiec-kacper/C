#include <stdio.h>

size_t strlen(const char* s){ //size _t is a data type that is used to represent the size of the objects in memory
    size_t length = 0; 

    while (*s != '\0'){
         length++;
         s++;
    }
    return length;
}

int main(){
    const char* test1 = "Mercedes";
    const char* test2 = "BMW";
    const char* test3 = "AUDI";

    printf("The size of %s is %zu \n", test1, strlen(test1)); //"%zu is used for size_t arguments"
    printf("The size of %s is %zu \n", test2, strlen(test2));
    printf("The size of %s is %zu", test3, strlen(test3));

    return 0;
}
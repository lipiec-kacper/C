#include <stdio.h>

char* strcat(char* dest, const char* src){
    char* result = dest;

    while (*dest != '\0'){
        printf("%c \n", *dest);
        dest++;
    }

    while(*src != '\0'){
        *dest = *src;

        dest++;
        src++;
    }

    *dest = '\0';

    return result;
}

int main(){
    char test[20] = "MERCEDES";
    const char* test2 = ">AUDI";

    printf("%s", strcat(test, test2));

    return 0;
}
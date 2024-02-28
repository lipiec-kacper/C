#include <stdio.h>

//Write the body of the function strcasecmp which returns an integer less than, equal to, or greater than zero 
//if s1 is found, respectively, to be less than, to match, or be greater than s2, 
//ignoring the cases of the characters. You don't have access to existing functions so you have to use this table.

int strcasecmp(const char *s1, const char *s2) {
    while (*s1 && *s2){
        char c1 = *s1;
        char c2 = *s2;

        if(c1 >= 'A' && c1 <= 'Z'){
            c1 += 32;
        }
        if(c2 >= 'A' && c2 <= 'Z'){
            c2 += 32;
        }

        if(c1 != c2){
            return c1 - c2;
        }
         s1++;
         s2++;    

    }

    if(*s1){
        return 1;
    }
    if(*s2){
        return -1;
    }

    return 0;
}


int main(){
    const char *test = "TEXT";
    const char *test2 = "text";

    int result = strcasecmp(test, test2);

    if(result == 0){
        printf("Strings are equal");
    }


}


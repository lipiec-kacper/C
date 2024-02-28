//Palindrome are strings of text which read the same backward as forward, i.e. : "racecar", "a man a plan a canal panama" or "kayak".

//Write the body of the function pal which tells if the given string is a palindrome or not. 
//Ignore spaces: for example, "kay a k" should be considered a palindrome. 
//An empty string is considered a palindrome. 
//You can use all the functions that are defined in string.h. 
//You can't modify the initial string.

#include <stdio.h>
#include <string.h>

int pal(char *str){
    if(str == NULL){
        return -1;
    }

    int len = strlen(str);

    if (len == 0){
        return 1;
    }


    int left = 0;
    int right = len - 1;

    while(left < right){

        while(str[left] == ' '){
            left++;
        }

        while(str[right] == ' '){
            right--;
        }

        char c1 = str[left];
        char c2 = str[right];

        if(c1 >= 'A' && c1 <= 'Z'){
            c1 += 32;
        }
        if(c2 >= 'A' && c2 <= 'Z'){
            c2 += 32;
        }

        if(c1 != c2){
            return 0;
        }    

        left++;
        right--;

    }

    return 1;
}

int main(){
    char *test = "racecar";

    int result = pal(test);

    if(result == 0){
        printf("not palindrome");
    }else if(result == 1){
        printf("palindrome");
    }else{
        printf("nulll");
    }


    return 0;
}
#include <stdio.h>

//INGINIOUS EXERCISES:


int main(){

    //Digital
    int number = 5;
    printf("The magic number is %d.\n", number);


    //Floating away

    float PI = 3.1415926;
    printf("pi = %.4f", PI);    //Here it will print 3.1416 it round off the fourth digit

    //sprintf
    //sprintf is a variant of printf which doesn't write to stdout, but instead write to buffer.
    //void format_str(char *buffer, unsigned int d, char *name, char initial) {
    //sprintf(buffer, "Mister %s %c. has %u eggs", name, initial, d);
}


//sprintf example : 
#include <stdio.h>

int main() {
    char buffer[100]; // Buffer to store the formatted string

    // Format a string with placeholders
    int num1 = 42;
    float num2 = 3.14159;
    char str[] = "example";

    sprintf(buffer, "Integer: %d, Float: %.2f, String: %s", num1, num2, str);

    // Print the formatted string
    printf("Formatted string: %s\n", buffer);

    return 0;
}
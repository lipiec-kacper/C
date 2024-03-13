#include <stdio.h>

int first (void *ptr){
  char *byte_ptr = (char *)ptr;

  byte_ptr += 12;

  int *int_ptr = (int *)byte_ptr;

  int value = *int_ptr;
  return value;  
}

char second(void *ptr){
  char *byte_ptr = (char *)ptr;
  byte_ptr += 6;

  return *byte_ptr;
}

int third(void *ptr){
  char *byte_ptr = (char *)ptr;

  byte_ptr += 45;

  int *int_ptr = (int *)byte_ptr;
  int result = *int_ptr;
  return result;
}

int main() {
    // Example usage
    int arr[] = {0, 1, 2, 3, 4, 5};  // Assume ptr points to the beginning of this array

    // Calculate the expected result manually (assuming int is 4 bytes)
    int expected_result = arr[3];  // 12 bytes after the beginning of the array

    // Call the function and compare the result
    int result = first(arr);
    printf("Result: %d\n", result);
    printf("Expected result: %d\n", expected_result);

    //second function usage
    // Example usage
    char *ptr = "abcdefqdfsfsd";  // Assume ptr points to the beginning of this string

    // Calculate the expected result manually
    char expected_result2 = ptr[6];  // 6 bytes after the beginning of the string

    // Call the function and compare the result
    char result2 = second(ptr);
    printf("Result: %c\n", result2);
    printf("Expected result: %c\n", expected_result2);


    //Third function usage :
    // Example usage
    int arr2[10];  // Assume ptr points to the beginning of this array

    // Assign some values to the array elements for testing
    for (int i = 0; i < 10; i++) {
        arr2[i] = i;
    }

    // Calculate the expected result manually
    int expected_result3 = arr2[11];  // 45 bytes after the beginning of the array

    // Call the function and compare the result
    int result3 = third(arr2);
    printf("Result: %d\n", result3);
    printf("Expected result: %d\n", expected_result3);
    return 0;
}

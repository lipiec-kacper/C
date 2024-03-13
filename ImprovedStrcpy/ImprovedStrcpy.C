#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char *buf_strcpy(const char *src){
    if (src == NULL){
        return NULL;
    }

    size_t len = strlen(src);

    char *dest = (char *)malloc((len + 1) * sizeof(char));

    if (dest == NULL){
      return NULL;
    }

    for(size_t i = 0; i < len; i++){
      dest[i] = src[i];
    }
    
    dest[len] = '\0';

    return dest;

}

int main(){
  const char *test = "dsfdsqfds";

  char *copied = buf_strcpy(test);

  if (copied == NULL){
    printf("an error ocured");
    return 1;
  }

  printf("Copied %s \n", copied);

  free(copied);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
* Crée un tampon/buffer de la même taille que {src}, et copie le contenu de {src} dans ce tampon/buffer.
*
* @src: chaine de caractères à copier
* @return: retourne le pointeur de la chaine de caractères copiée. Si {src} == NULL ou en cas d'erreur, retourne NULL
*
* Rappelez-vous que les chaînes de caractères se terminent par '\0' et que strlen("abc") retourne 3 même si 4 octets sont nécessaires pour stocker cette chaîne.
*/
char *buf_strcpy(const char *src) {
if(src == NULL){
    return NULL;
}
int src_length = strlen(src);
char *tampon = malloc((src_length + 1) * sizeof(char));
if(tampon == NULL){
    return NULL;
}
for(int i = 0; i < src_length; i++){
    tampon[i] = src[i];
}

tampon[src_length] = '\0'; 

return tampon;
}

int main(){
  const char *src = "test";
  char *result = buf_strcpy(src);
  printf("%s", result);
  return 0;
}

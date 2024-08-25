#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <signal.h>
#include <sys/uio.h>
/*
 * @pre filename != NULL, index >= 0
 * @post retourne l'entier à l'index {index} du tableau dans le fichier {filename}.
 * retourne -1 en cas d'erreur.
 * retourne -2 si index >= longueur du tableau.
 */
int get(char *filename, int index) {
   if(filename == NULL || index < 0){
    return -1;
  }

  int fd;
  int element;
  int *map;
  struct stat file_stat;
  
  if ((fd = open (filename, O_RDONLY)) < 0) {
    perror("open(source)");
    return -1;
  }

  if (fstat (fd,&file_stat) < 0) {
    perror("fstat");
    return -1;
  }

  map = mmap (NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if(map == MAP_FAILED){
    close(fd);
    return -1;
  }

  if(index >= file_stat.st_size / sizeof(int)){
    munmap(map, file_stat.st_size);
    close(fd);
    return -2;
  }

  element = map[index];

  if(munmap(map,file_stat.st_size)<0) {
    perror("munmap(src)");
    return -1;
  }
  

  if(close(fd)<0) {
    perror("close(file1)");
    return -1;
  }
  return element;

 }



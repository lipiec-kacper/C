#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int copy(char *file_name, char *new_file_name) {
  int src_fd, dest_fd;
  void *src, *dst;
  struct stat file_stat;
  char dummy = 0;
  if ((src_fd = open(file_name, O_RDONLY)) < 0) {
    perror("open(source)");
    return -1;
  }

  if (fstat(src_fd, &file_stat) < 0) {
    perror("fstat");
    return -1;
  }
  // ouverture fichier destination
  if ((dest_fd = open(new_file_name, O_RDWR | O_CREAT | O_TRUNC,
                      file_stat.st_mode)) < 0) {
    perror("open(dest)");
    return -1;
  }

  // le fichier destination doit avoir la même taille que le source
  if (lseek(dest_fd, file_stat.st_size - 1, SEEK_SET) == -1) {
    perror("lseek");
    return -1;
  }

  // écriture en fin de fichier
  if (write(dest_fd, &dummy, sizeof(char)) != 1) {
    perror("write");
    return -1;
  }

  // mmap fichier source
  if ((src = mmap(NULL, file_stat.st_size, PROT_READ, MAP_SHARED, src_fd, 0)) ==
      (void *)(-1)) {
    perror("mmap(src)");
    return -1;
  }

  // mmap fichier destination
  if ((dst = mmap(NULL, file_stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED,
                  dest_fd, 0)) == (void *)(-1)) {
    perror("mmap(src)");
    return -1;
  }

  // copie complète
  memcpy(dst, src, file_stat.st_size);

  // libération mémoire
  if (munmap(src, file_stat.st_size) < 0) {
    perror("munmap(src)");
    return -1;
  }

  if (munmap(dst, file_stat.st_size) < 0) {
    perror("munmap(dst)");
    return -1;
  }
  // fermeture fichiers
  if (close(src_fd) < 0) {
    perror("close(file1)");
    return -1;
  }

  if (close(dest_fd) < 0) {
    perror("close(file2)");
    return -1;
  }
  return 1;
}

int main() {
  char *src = "./src.txt";
  char *dest = "./dest.txt";

  copy(src, dest);
}

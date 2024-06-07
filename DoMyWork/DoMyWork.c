#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *long_computing(void *);
void *backup_computin(void *);

struct ThreadArgs {
  void *(*function)(void *);
  char *argument;
};

int doMyWork(void *long_computing(void *), void *backup_computin(void *),
             char *string, int ret_value) {
  pthread_t thread1, thread2;
  int result1, result2;

  result1 =
      pthread_create(&thread1, NULL, long_computing, (void *)&long_computing);
  if (result1 != 0) {
    return -1;
  }

  int *ret_val_ptr;

  result1 = pthread_join(thread1, (void **)&ret_val_ptr);

  if (result1 != 0) {
    return -2;
  }

  if (*ret_val_ptr != ret_value) {
    result2 = pthread_create(&thread2, NULL, backup_computin,
                             (void *)&backup_computin);

    if (result2 != 0) {
      return -3;
    }

    result2 = pthread_join(thread2, NULL);

    if (result2 != 0) {
      return -4;
    }

    return *ret_val_ptr;
  }
  return *ret_val_ptr;
}

void *long_computing(void *arg) {

  int *ret_val_ptr = (int *)malloc(sizeof(int));
  *ret_val_ptr = 42;
  return (void *)ret_val_ptr;
}

void *backup_computin(void *arg) {
  int *ret_val_ptr = (int *)malloc(sizeof(int));
  *ret_val_ptr = 24;
  return (void *)ret_val_ptr;
}

int main() {
  char inputString[] = "HELLO WORD!";
  int ret_value = 42;

  int result =
      doMyWork(long_computing, backup_computin, inputString, ret_value);

  if (result == ret_value) {
    printf("Computation successful. Result: %d\n", result);
  } else {
    printf("Computation failed. Backup result: %d\n", result);
  }

  return 0;
}

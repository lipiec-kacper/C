/*
 * pre:
 * - list n'est pas null
 * - Pour chaque paire a, b d'éléments dans la liste, a.key != b.key
 * post:
 * - S'il y a un élément avec la clé 'key dans la liste, celui-ci est retiré
 * - retourne la clé "key' de l'élément retiré
 * - retourne 0 si aucun élément n'a été trouvé pour cette clé
 */
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
  int key;
  int data;
  struct Node *next;
} Node;

// List structure
typedef struct {
  Node *head;
} list_t;

void initList(list_t *list) { list->head = NULL; }

void addElement(list_t *list, int key, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->key = key;
  newNode->data = data;
  newNode->next = list->head;
  list->head = newNode;
}

int delete(list_t *list, int key) {
  if (list == NULL || list->head == NULL) {
    return 0;
  }

  Node *current = list->head;
  Node *previous = NULL;

  while (current != NULL) {
    if (current->key == key) {
      // if node to delete is the head
      if (previous == NULL) {
        list->head = current->next;
      } else {
        previous->next = current->next;
      }
      int removedKey = current->key;
      free(current);
      return removedKey;
    }
    previous = current;
    current = current->next;
  }
  return 0;
}

int main() {
  list_t myList;
  initList(&myList);

  addElement(&myList, 1, 5);
  addElement(&myList, 2, 6);
  addElement(&myList, 3, 7);

  int removed = delete (&myList, 2);
  printf("The key: %d has been deleted\n", removed);

  removed = delete (&myList, 4);
  printf("%d\n", removed);

  return 0;
}

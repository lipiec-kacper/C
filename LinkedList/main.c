#include <stdio.h>
#include <stdlib.h>

typedef struct {
  void *next;
  int data;
} Node;

Node *head = NULL;
// insert
Node *insertNode(int data, int position) {
  Node *current = head;

  while (current != NULL && position != 0) {
    position--;
  }

  if (position != 0) {
    return NULL;
  }

  Node *new = malloc(sizeof(Node));
  if (new == NULL) {
    return NULL;
  }
  new->data = data;
  new->next = current->next;
  current->next = new;

  return new;
}

// delete
int delete(int data) {
  Node *current = head;
  Node *previous = head;
  while (current != NULL) {
    if (current->data == data) {
      if (current == head) {
        head = current->next;
      } else {
        previous->next = current->next;
        free(current);
      }
      return 1;
    }
    previous = current;
    current = current->next;
  }
  return 0;
}

// add

Node *addNode(int data) {
  Node *new = NULL;
  if (head == NULL) {
    new = malloc(sizeof(Node));
    if (new == NULL) {
      return NULL;
    }
    new->data = data;
    head = new;
    new->next = NULL;
  } else {
    new = malloc(sizeof(Node));
    if (new == NULL) {
      return NULL;
    }
    new->data = data;
    new->next = head;
    head = new;
  }
  return new;
}

// print
void printList() {
  Node *current = head;
  printf("\n");
  while (current != NULL) {
    printf("%d ->", current->data);
    current = current->next;
  }
  printf("\n");
}

void printMenu() {
  printf("1\t Insert value\n");
  printf("2\t Delete value\n");
  printf("3\t Add value\n");
  printf("4\t Print List\n");
  printf("5\t Quit\n");
}

int main(int argc, char **argv) {
  int choice = 0;
  int option = 0;
  int option2 = 0;
  while (choice != 5) {
    printMenu();
    int num_received = scanf("%d", &choice);
    if (num_received == 1 && choice >= 1 && choice <= 5) {
      switch (choice) {
      case 1:
        // insert
        printf("What data should I insert ?\n");
        scanf("%d", &option);
        printf("what positon ?\n");
        scanf("%d", &option2);
        Node *new = insertNode(option, option2);
        if (new == NULL) {
          printf("An error while inserting\n");
        }
        break;
      case 2:
        // Delete
        printf("What data should I delete ?\n");
        scanf("%d", &option);
        int succes = delete (option);
        if (!succes) {
          printf("Value not found in the list");
        }
        break;
      case 3:
        // Add
        printf("What data should I add to the list ?\n");
        scanf("%d", &option);
        new = addNode(option);
        if (new == NULL) {
          printf("Error while adding a value");
        }
        break;
      case 4:
        // Print
        printList();
        break;
      case 5:
        break;
      }
    }
  }

  return 0;
}

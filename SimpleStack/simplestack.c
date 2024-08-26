#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  struct node *next;
  char *name;
};
/**
* Remove the top element of the stack and return its content.
*
* @head : pointer to the top of the stack
* @result : pointer to store the popped element
*
* @return 0 if no error, 1 otherwise
*
* pre : @result contains a null-terminated correct string
* post : @result contains the string @name from the element at the top of the stack
*/

int pop(struct node **head, char *result){
  if(head == NULL){
    return 1;
  }

  return 0;
}

/**
* Add @name at the "top" of the stack.
*
* @head : pointer to the top of the stack
* @name : the string to be placed in the element at the top of the stack
*
* @return 0 if no error, 1 otherwise
*/

int push(struct node **head, const char *value){
  // Create a new node
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  if (new_node == NULL) {
    return -1; // Memory allocation failed
  }

  // Initialize the new node
  strncpy(new_node->name, value, sizeof(new_node->name) - 1);
  new_node->name[sizeof(new_node->name) - 1] = '\0'; // Ensure null termination
  new_node->next = NULL;

  // If the list is empty, make the new node the head
  if (*head == NULL) {
    *head = new_node;
  } else {
    // Traverse to the last node
    struct node *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    // Attach the new node at the end
    current->next = new_node;
  }

  return 0; // Success
}
void printList(struct node *head) {
  struct node *current = head;
  while (current != NULL) {
    printf("%s -> ", current->name);
    current = current->next;
  }
  printf("NULL\n");
}

int main() {
  struct node *head = NULL;

  push(&head, "Node1");
  push(&head, "Node2");
  push(&head, "Node3");

  printList(head);

  return 0;
}


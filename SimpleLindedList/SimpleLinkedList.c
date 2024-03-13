#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  struct node *next;
  int value;
}node_t;

node_t *init_node(int value){
  //Allocate memory for the node
  node_t *newNode = (node_t *)malloc(sizeof(node_t));

  //check
  if(newNode == NULL){
    return NULL;
  }

  newNode->next=NULL;
  newNode->value=value;

  return newNode;
}


int add_node(list_t *list, int value) {
    // Allocate memory for a new node
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    
    // Check if memory allocation was successful
    if (new_node == NULL) {
        return 1; // Return 1 to indicate failure
    }

    // Initialize the new node with the given value
    new_node->value = value;

    // Update the next pointer of the new node to point to the current first node of the list
    new_node->next = list->first;

    // Update the first pointer of the list to point to the newly created node
    list->first = new_node;

    // Increment the size member of the list
    list->size++;

    return 0; // Return 0 to indicate success
}

 int main() {
    // Test the init_node function
    int value = 10;
    node_t *new_node = init_node(value);

    if (new_node != NULL) {
        printf("Node created successfully with value: %d\n", new_node->value);
        free(new_node); // Free the allocated memory
    } else {
        printf("Error: Failed to create node.\n");
    }

    return 0;

}

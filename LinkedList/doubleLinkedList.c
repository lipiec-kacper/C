#include <stdio.h>
#include <stdlib.h>


struct node{
  struct node *prev;
  int data;
  struct node *next;
};

int print_list(struct node *nd){
  struct node *head = nd;
  while(head != NULL){
    printf("%d", head->data);
    printf("\n");
    head = head->next; 
  }
  
  return 0;
}

int insert_new_node(int data, struct node *node){
  struct node *current = node;
  
  while (current != NULL){
    current->prev = current;
    current = current->next;
  }
  current = malloc(sizeof(current));
  if(current == NULL){
    printf("Memory allocation failled");
    return -1;
  }
  current->prev = current;
  current->data = data;
  current->next = NULL;

  return 0;
}

int delete_node(int data, struct node *node){
  struct node *current = node;

  if(current == NULL){
    printf("The node is empty \n");
    return -1;
  }

  while(current->data != data){
    current = current->next;
  }
  printf("%d deleted \n", current->data);
  current = current->prev;
  current->next = current->next->next;
  return 0;
}

int main(){
  struct node *head = malloc(sizeof(head));
  head->prev = NULL;
  head->next = NULL;
  
  insert_new_node(20, head);
  insert_new_node(30, head);
  insert_new_node(40, head);
  insert_new_node(50, head);
  delete_node(30, head);
  print_list(head);
  return 0;
}

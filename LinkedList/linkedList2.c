#include <stdio.h>
#include <stdlib.h>


struct node{
  int data;
  struct node *link;
};

int insertNewNode(struct node *node, int data){
  struct node *head = node; //dereference
  struct node *previous = head;
  struct node *current = head;
  if(head == NULL){
    return -1;
  }
  while(current != NULL){
    previous = current;
    current = current->link;
  }
  
  current = malloc(sizeof(current));
  current->data = data;
  previous->link = current;

  return 0;
}

int print_list(struct node *node){
  struct node *head = node;
  
  while(head != NULL){
    printf("%d", head->data);
    printf("\n");
    head = head->link;
  }

  return 0;
}

int main(){
  struct node *head = malloc(sizeof(head));
  head->data = 6;
  head->link = NULL;

  insertNewNode(head, 45);
  print_list(head);
  insertNewNode(head, 76);
  print_list(head);
  

  return 1;
}


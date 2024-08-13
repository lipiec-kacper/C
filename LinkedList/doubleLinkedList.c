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

int main(){
  struct node *head = malloc(sizeof(head));
  head->prev = NULL;
  head->data = 10;
  head->next = NULL;
  print_list(head);
  return 0;
}

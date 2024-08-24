//Une liste doublement chaînée est implémentée comme suit. Cette structure de données permet d'enregistrer un ensemble d'éléments, en liant pour chacun une clé à une valeur. 
//On va faire l'hypothèse dans cette question qu'il n'y a qu'un seul exemplaire de chaque clé dans la liste.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int key;
    double value;
    struct node* next;
    struct node* prev;
} node_t;

typedef struct list {
    node_t* head;
    node_t* tail;
} list_t;

list_t* create_list() {
    list_t* list = (list_t*) malloc(sizeof(list_t));
    if (list == NULL) {
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;

    return list;
}

int insert(list_t* list, int key, double value) {
    node_t* node = (node_t*) malloc(sizeof(node_t));
    if (node == NULL) {
        return -1;
    }

    node->key = key;
    node->value = value;
    node->next = NULL;

    if (list->tail == NULL) {
        list->head = node;
        node->prev = NULL;
    } else {
        list->tail->next = node;
        node->prev = list->tail;
    }

    list->tail = node;
    return 0;
}

void free_list(list_t* list) {
    node_t* current = list->tail;

    if (current == NULL) {
        free(list);
        return;
    }

    while (current->prev != NULL) {
        current = current->prev;
        free(current->next);
    }

    free(current);
    free(list);
}


void print_list(list_t* list) {
    node_t* current = list->head;
    while (current != NULL) {
        printf("Key=%d, Value=%f\n", current->key, current->value);
        current = current->next;
    }
}

void print_elem(list_t* list, int key) {
    node_t* current = list->head;
    while (current != NULL) {
        if (current->key == key) {
            printf("Key=%d, Value=%f\n", current->key, current->value);
            return;
        }
        current = current->next;
    }
    printf("No element found for Key=%d\n", key);
}


/*
 * pre:
 * - list n'est pas null
 * - Pour chaque paire a, b d'éléments dans la liste, a.key != b.key
 * post:
 * - S'il y a un élément avec la clé `key` dans la liste, celui-ci est retiré
 * - retourne la valeur `value` de l'élément retiré
 * - retourne 0.0 si aucun élément n'a été trouvé pour cette clé
 */
double delete(list_t* list, int key){
  if(list == NULL){
    return -1.0;
  }
  node_t *current = list->head;
  
  //list->head->key or value
  //list->head->next or prev
  //list->tail->ket or value
  //liest->tail->next or prev
  double current_first = current->value;

  if(current->key == key && current->prev == NULL){
    list->head = current->next;
    if(list->head != NULL){
      list->head->prev = NULL;
    }else{
      list->tail = NULL;
    }
    free(current);
    return current_first;
  }
  
  while(current->key != key && current != NULL){
    current = current->next;
  }
//si aucun élément trouvé
  if(current == NULL){
    return 0.0;
  }
  
  double return_value = current->value;

  if(current->prev != NULL && current->next != NULL){
    current->prev->next = current->next;
    current->next->prev = current->prev;
  }

  if(current->next == NULL){
    list->tail = current->prev;
    if(current->prev != NULL){
      current->prev->next = NULL;
    }
  }

  free(current);
  
  return return_value;
}


int main(){
  // vos tests

// Un exemple de test
list_t* list = create_list();
  insert(list, 1, 25.0);
  insert(list, 2, 50.0);
  insert(list, 3, 75.0);
  insert(list, 4, 80.0);

  double result = delete(list, 4);

  print_list(list);

}

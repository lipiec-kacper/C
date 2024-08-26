#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct {
  char nom[50];   // nom de l'étudiant.e
  char prenom[50]; // prénom de l'étudiant.e
  float* cotes;    // tableau contenant les cotes sur 20
  int nombreCotes;  // nombre de cotes encodées
  pthread_mutex_t mutex;
} Etudiant;

/*
 * @pre arg!=NULL, contient un pointeur vers une structure Etudiant
 * @post retourne la moyenne des cotes de l'étudiant.e. Retourner NULL en cas d'erreur.
 */

void * calculerMoyenne(void *arg){
  if(arg == NULL){
    return NULL;
  }

  Etudiant *etudiant = (Etudiant*) arg;
  float *moyenne = malloc(sizeof(float));
  if(moyenne == NULL){
    return NULL;
  }

  pthread_mutex_lock(&etudiant->mutex); //try to delete & in inginious

  float somme = 0;
  for(int i = 0; i < etudiant->nombreCotes; i++){
    somme += etudiant->cotes[i]; 
  }
  
  *moyenne = (float)somme / (float)etudiant->nombreCotes;
  pthread_mutex_unlock(&etudiant->mutex);

  return (void *)moyenne;

}

int main(int arg, char **argv) {
  Etudiant etudiant;
  strcpy(etudiant.nom, "Tartempion");
  strcpy(etudiant.prenom, "Jules");
  etudiant.nombreCotes = 3;
  // Allocation dynamique des cotes
  etudiant.cotes = (float*)malloc(etudiant.nombreCotes * sizeof(float));
  // Remplissage des cotes
  etudiant.cotes[0] = 12;
  etudiant.cotes[1] = 14;
  etudiant.cotes[2] = 10;

  pthread_mutex_init(&etudiant.mutex, NULL);

  // Calcul de la moyenne dans un thread
  void * ret;
  pthread_t thread;
  pthread_create(&thread, NULL, (void*)calculerMoyenne, &etudiant);
  pthread_join(thread, &ret);
  // Affichage de la moyenne
  float *moyenne=(float *)ret;
  printf("Moyenne : %.2f\n", *moyenne);
  // Libération des ressources
  free(etudiant.cotes);
  free(ret);
  pthread_mutex_destroy(&etudiant.mutex);
  return 0;
}

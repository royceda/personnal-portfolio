#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>



/*genere un nombre entre 0 et 9*/

int aleatoire(){
  srand(time(NULL)+getpid());
  float max = 10;
  int nombre = (int)(max*rand()/RAND_MAX);
  return (nombre);
}



/*variable globale*/
//int alea;
int m[2];
//pipe(m);
 
void* ecriture(void *a){
    
  int i;
  for(i=0; i<2; ++i){
    close(m[0]);
    int alea2 = calculerP();
    printf("ecriture = %d \n", alea2);
    write(m[1], &alea2, sizeof(int));
    close(m[1]);
  }
  close(m[1]);
  return NULL;
}


void* lecture(void *a){
  int alea = (int) a;
  int i;
  for(i=0; i<2; i++){
    int lu;
    read(m[0], &lu, sizeof(int));
    alea += lu;
    printf("lecture = %d \n", alea);
  }
  close(m[0]);
  for(i=0; i<2; ++i){
    int status;
    wait(&status);
  }
    
  return NULL;
}


int calculerP(){
  
  int m[2];
  pipe(m); 
  pthread_t E,L;
  int alea = aleatoire();
  if(alea<5){

    pthread_create(&E, NULL, ecriture, (void*) alea);
    pthread_create(&L, NULL, lecture, (void*) alea);
    pthread_join(E, NULL);
    pthread_join(L, NULL);
    
  }
  printf("alea: %d\n", alea);
  return alea;
}


int main(int argc, char *argv[]){

  calculerP();

  exit(EXIT_SUCCESS);
}



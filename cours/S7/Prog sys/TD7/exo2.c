#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#include <fcntl.h>           /* For O_* constants */
#include <semaphore.h>
#include <sched.h>

#define TAILLE 1000000
int N;
int A[TAILLE] ={0};
sem_t * my_sem;


void *starte (void *ptr)  {
  int i;
  int j;
  my_sem = malloc(sizeof(sem_t));
  for(i=0; i<10; ++i) {
    for(j=0; j<TAILLE; ++j) {
      A[j]++;
      sem_post(my_sem);
    }
    printf("ecrivain %d effectue\n", i+1);
    sched_yield();
  }
  return NULL;
}


void *startl (void *ptr)  {
  int i;
  int j;
  int tot;
  for(i=0; i<10; ++i) {
    tot = 0;
    for(j=0; j<TAILLE; ++j) {
      sem_wait(my_sem);
      tot += A[TAILLE-j-1];
    }
    printf("lecture tot : %d \n", tot);
    if(tot%2) {
      printf("tot impair \n");   
      sched_yield();
      sem_post(my_sem);
    }
        
  }
  return NULL;
}


int
main(int argc, char* argv[]) {
  int ret;
  /*
  if(argc == 3)
    N = atoi(argv[1]);
  else return EXIT_FAILURE;
  */

  my_sem = sem_open(argv[2], O_CREAT, S_IRWXU,  1);
  if(my_sem == SEM_FAILED) {
    perror("sem_open");
    exit(EXIT_FAILURE);
    }
  pthread_t ecrivain;
  pthread_t lecteur;



  ret = pthread_create(&ecrivain, NULL, starte, NULL);
  if (ret < 0) {
    perror("pthread_create");
    exit(EXIT_FAILURE);
  }    
  ret = pthread_create(&lecteur, NULL, startl, NULL);
  if (ret < 0) {
    perror("pthread_create");
    exit(EXIT_FAILURE);
  }    

  pthread_join(ecrivain, NULL);
  pthread_join(lecteur, NULL);

  if (sem_close(my_sem) == -1) {
    perror("semaphore");
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}

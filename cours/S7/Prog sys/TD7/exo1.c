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


#define POOL 8

int G = 123;
int N;
sem_t * mysem;
int total;

void *start (void *ptr)  {
  int my_n = 0;
  
  sem_wait(mysem);
  while(N > 0) { 
    N--;
    sem_post(mysem);
    my_n++;
    sem_wait(mysem);
  }
  sem_post(mysem);
  
  total += my_n;
  printf("%d\n", my_n);
  return NULL;
}


int
main(int argc, char* argv[]) {
  int i;
  total = 0;

  if(argc == 3)
    N = atoi(argv[1]);
  else return EXIT_FAILURE;

  mysem = sem_open(argv[2], O_CREAT, S_IRWXU,  1);
  if(mysem == SEM_FAILED) {
    perror("sem_open");
    exit(EXIT_FAILURE);
  }
  pthread_t th[POOL];
  pid_t x = getpid();

  for(i=0; i<POOL; i++) {
    int ret = pthread_create(&th[i], NULL, start, (void *)(intptr_t) x);
    if (ret < 0) {
      perror("pthread_create");
      exit(EXIT_FAILURE);
    }    
  }
  for(i=0; i<POOL; i++) {
    pthread_join(th[i], NULL);
  }

  printf("total = %d\n", total);
  if (sem_close(mysem) == -1) {
    perror("semaphore");
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}

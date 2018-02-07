#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>

#include <stdint.h>

#define POOL 8



void* start(void *arg) {

  int x = (int)(intptr_t)arg;
  printf("thread pid %d \n",x);
  return NULL;
}



int main () {

  pthread_t th[POOL];
  pid_t x = getpid();
  int i;
  
  for(i = 0; i<POOL; i++) {
    int ret = pthread_create(&th[i], NULL, start, (void *)(intptr_t)x);
    //intptr_t dans stdint.h pour le cast
    if(ret<0) {
      perror("pthread");
      exit(EXIT_FAILURE);
      }
  }
  
    for(i = 0; i<POOL; i++)
      pthread_join(th[i], NULL);




  return EXIT_SUCCESS;
}

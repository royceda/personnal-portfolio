#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdint.h>

#define POOL 8

int k = 0;

void *start(void *arg){
  int var = 10;
  int d = (int)(intptr_t)arg;
  k++;
  var++;
  printf("PID principale: %d\n PID = %d \n k = %d\n var: %d\n",(int)getpid(), d,k, var);
  return NULL;
}


int main(){
  
  pthread_t th[POOL];
  int ret;
  int x = getpid();

  for(int i= 0; i<POOL; ++i){  
    ret =  pthread_create( &th[i], NULL ,start, (void*)(intptr_t)x);
    if( ret == -1){
      perror("pthread_create()"); 
      exit(1);
    }
  }
  for(int i = 0; i<POOL; ++i){  
    printf("attente de %d\n", i+1);
    pthread_join(th[i], NULL);
  }
  

  return 0;
}

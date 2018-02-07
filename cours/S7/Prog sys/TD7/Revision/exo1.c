#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#include <pthread.h>


#define POOL 8
#define CHK(X) if((X) == -1){perror(#X);exit(1);}

int tickets = 64;

void *seller(void *a){

  int k = 0;
  while(tickets > 0){
    tickets--;
    sleep(3);
    k++;
    printf("*");
  }
  printf("vendu %d\n", k);
  
  return NULL;
}

int main(){

  pthread_t th[POOL];
  int ret, i;
 
  //while(tickets >0)
    for(i =0; i<POOL; ++i){
      printf("thread %d: \t", i);
      CHK(ret = pthread_create(&th[0], NULL, seller, NULL));
      sleep(1);
      printf("tickets restant: %d\n", tickets);
    }
  
  /*
  for(i = 0; i<POOL; ++i){
    pthread_join(th[i], NULL);
    }*/




  return 0;
}

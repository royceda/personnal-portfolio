#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* start(void * pid)
{
  printf("pid : %u \n", (unsigned int)pid);
  return NULL;
}

int main(int argc, char**argv){
  
  pthread_t thread;
  pthread_t th[8];
  pid_t x = getpid();
  
  //pthread_create(&thread, NULL, start,(void *)getpid());
  
  for(int i = 0; i<8; i++)
    pthread_create(&th[i], NULL, start,(void *)getpid());
  
   for(int i = 0; i<8; i++)
     {
       void *ret;
       pthread_join(th[i],&ret);
     }

   printf("processus %d termine \n", getpid());


  //  pthread_join(thread,NULL);


  return EXIT_SUCCESS;
}



/*
  
  pthread_t thread;
  pthread_t th[8];
  pthread_create(&thread, NULL, start,(void *)getpid());
  
  for(int i = 0; i<8; i++)
    pthread_create(th[i], NULL, start,(void *)getpid());
  
  //  pthread_join(thread,NULL);


*/

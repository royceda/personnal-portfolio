#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


#define PHILOSOPHE 5
pthread_mutex_t baguette[PHILOSOPHE];

int lock;


void* mange(int id){
 
  printf("%d est en train de manger...\n", id);
  printf("\n");
  for(int i=0; i<2; i++){
    //sleep(1);
  }
    //il bouffe
  return NULL;
}

void* philo(void* a){

  int id    = (int) a;
  int left  = id;
  int right = id+1 % PHILOSOPHE;
  int ret;
  //while(1){
    printf("%d: pense\n", id);
    if(left<right) {
      ret = pthread_mutex_lock (&baguette[right]);
      if(ret == EDEADLK){prinf("DEADLOCK\n"); exit(1);}
      printf("%d: possede la gauche %d \n", id, left);
      
      pthread_mutex_lock (&baguette[left]);
      printf("%d: possede la droite %d \n", id, right);
    }
    else if (left > right){      
      pthread_mutex_lock (&baguette[left]);
      printf("%d: possede la gauche %d \n", id, left);
      
      pthread_mutex_lock (&baguette[right]);
      printf("%d: possede la droite %d \n", id, right);
    }

    printf("le philosophe [%d] mange avec les baguettes %d et %d \n \n", id, left, right);
    mange(id);
    
    pthread_mutex_unlock( &baguette[left]);
    printf("%d: libere gauche %d\n", id, left);
    
    pthread_mutex_unlock( &baguette[right]);
    printf("%d: libere droite  %d\n", id, right);

  
    //  }

  return NULL;
}


int main(){
  
  pthread_t P[PHILOSOPHE];
  int i;
 
  while(1){
    for(i = 0; i<PHILOSOPHE; i++)
      pthread_create(&P[i], NULL, philo, (void*)i);
    
    for(i = 0; i<PHILOSOPHE; i++);
    pthread_join(P[i], NULL);
  }
  return 0;
}

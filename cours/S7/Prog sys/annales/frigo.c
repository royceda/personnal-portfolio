#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int verif;

void commande(){
  verif = 0;
}



void* verifi(void* a){

  int id = (int)a;
  if(verif == 1){
    printf("%d a verifié\n", id);
    sleep(10);
    return NULL;
  }
  else
    {
      printf("%d commande\n", id);
      verif=0;
    }
  return NULL;
}


int main(){

  verif = 0;
  pthread_t T[5];
  while(1){
    for(int i = 0; i<5; ++i)
      pthread_create(&T[i], NULL, verifi, (void*)i);
    
    for(int i = 0; i<5; ++i)
      pthread_join(T[i], NULL);
  }




  return 0;
}

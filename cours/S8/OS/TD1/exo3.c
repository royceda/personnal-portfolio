#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <asm/unistd.h>

int main(){
  
  unsigned long microsec;
  struct timeval tv1, tv2;

 

  gettimeofday(&tv1, NULL);


  /*code de mesure*/
  
  for(int i = 0; i < 100000; ++i)
    sched_yield();
  

 /*chose � mesurer*/
  gettimeofday(&tv2, NULL);
  microsec = (tv2.tv_sec-tv1.tv_sec)*1000000
    +(tv2.tv_usec-tv1.tv_usec);

  printf("microsec: %ld \n", microsec);
  
  
  return 0;
}

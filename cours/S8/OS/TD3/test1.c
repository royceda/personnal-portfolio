#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>

#include <fcntl.h>


#define SIZE 128


void main1(){
  printf("%d\n", (int)getpid());

  char *buffer, *buffer2, *buffer3;
  int fd, fd1, fd2;
  fd = open("toto", O_RDWR|O_CREAT);
  fd1 = open("toto1", O_RDWR|O_CREAT);
  fd2 = open("toto2", O_RDWR|O_CREAT);
  if(fd<0)
    {
      perror("open");
      return EXIT_FAILURE;
    }
  buffer = mmap(NULL, 128,  PROT_READ|PROT_WRITE, MAP_SHARED,fd,0);
  
  buffer2 = mmap(NULL, 128,  PROT_READ|PROT_WRITE, MAP_PRIVATE,fd1,0);
  buffer3 = mmap(NULL, 128,  PROT_READ|PROT_WRITE, MAP_SHARED,fd2,0);
  if(buffer == MAP_FAILED)
    {
      perror("mmap");
      exit(EXIT_FAILURE);
    }
  //buffer[1] = 'a';
  //buffer[127] = 'b';
  //munmap(buffer, SIZE);
  while(1){
  }
  close(fd);
}



void main2(){

  void *B;
  unsigned int i= 0;

  while(1){
    B = calloc(1000,1);
    B =45566;
    printf("%d ko \n", ++i);
  }


}


int main(){
 
  main2();



  return 0;
}

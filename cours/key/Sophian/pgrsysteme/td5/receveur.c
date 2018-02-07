#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define SIZE 128

char *buffer;

void myhandler(int x){

  printf("signal : %d",x);
  printf("recu : %s\n",buffer);
}

int main(int argc, char *argv[])
{ 

  int i=0;
  struct sigaction my_action, old_action;
  int f = open("texte.txt",O_RDWR);
 
  printf(" pid %u \n ", getpid());

  if (f==-1)
    {
      perror("open");
      exit(1);
    }
  buffer = mmap(NULL, SIZE, PROT_READ|PROT_WRITE, MAP_SHARED,f, 0);

  if(buffer == MAP_FAILED){
    perror("mmap");
    exit(1);
  }
  
  sprintf(buffer, "%u", (int)getpid());
  printf("%s", buffer);
 
  my_action.sa_handler = myhandler;
  sigemptyset(&my_action.sa_mask);
  my_action.sa_flags = 0;
  
  //sigaction( SIGUSR1, myhandler);
  sigaction(SIGUSR1, &my_action, &old_action);
  pause();
  
  
  //sigaction( SIGUSR1, SIG_DFL);
  sigaction( SIGUSR1, &old_action, NULL);
  
  
  munmap(buffer,SIZE);
  
  close(f);
  

  

  return EXIT_SUCCESS;



}

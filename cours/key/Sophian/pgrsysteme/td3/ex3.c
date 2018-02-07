#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#define CHAINE1 "a"
#define CHAINE2 "b \n"

int main (int argc, char** argv) 
{
  pid_t p;
  int i;
  printf("pid %u", getpid());
  // fflush(stdout); // or use write
  switch(p = fork()){
  case -1:
    perror("fork");
    return EXIT_FAILURE;
    break;
  case 0:  //child
    printf("child pid %u", getpid());
    printf("child ppid %u\n", getppid());
    break;
   default: //father
     wait(&i);
  }
  _exit(0);
}

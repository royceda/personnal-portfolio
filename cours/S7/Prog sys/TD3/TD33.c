#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>







int main(int argc, char *argv[])
{

  pid_t d = fork();
  /*
  pid_t getpid();
  getppid();
  */
  if(d == 0)
    {
      printf(" pere: %ld \n fils: %ld \n", (long)getppid(), (long)getpid()); 
      exit(0);
    }
  else
    printf("nom fils est %ld \n", (long)d);
  exit(0);



  //La bufferisation se duplique 
  //  return 0;
}


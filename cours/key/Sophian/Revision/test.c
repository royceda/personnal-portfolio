#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv){
  int i = 0;
  int n = argc - 1;
  do{
    if(fork() != 0){
      printf("Je suis le pere, pid: %u, ppid: %u\n", getpid(),getppid());
    }
    else{
      printf("Je suis le fils, pid: %u, ppid: %u\n", getpid(),getppid());
      break;
    }
    i++;
  } while(i<n-1);

  printf("pid: %d de la boucle:%d\n", getpid(),i);
    
}

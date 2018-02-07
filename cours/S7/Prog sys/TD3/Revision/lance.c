#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[]){
  
  int fd;
  if( argc < 2)
    return EXIT_FAILURE;
  
  switch( fork()){
  case -1:
    perror("fork() failed");
    return EXIT_FAILURE;
    break;

  case 0: //dans le pere
    fd = open(argv[1], O_CREAT|O_WRONLY|O_TRUNC,0666);
    if( fd ==-1){
      perror("open() failed");
      return EXIT_FAILURE;
    }

    else if( dup2(fd,1) == -1){
      perror("dup2 failed");
      return EXIT_FAILURE;
    }
    if(execvp(argv[1], argv+1) == -1){
      perror("execvp() failed");
      return EXIT_FAILURE;
    }
    break;
  }

  return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv){
  
  int fd = open(argv[2],O_WRONLY);
  dup2(fd,STDOUT_FILENO);
  pid_t d = fork();
  if(d !=0 && d != -1)
    waitpid(d,NULL,0);
  
  while( execve(argv[1],NULL,NULL) == -1)
    printf("erreur execution %s\n", argv[1]);
  
  close(fd);
  return EXIT_SUCCESS;
}

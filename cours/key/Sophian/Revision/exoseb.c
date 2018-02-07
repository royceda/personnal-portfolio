#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256
int main(int argc, char **argv){
  int tube[2];
  pipe(tube);
  pid_t d = fork();
  if(d == -1)
    fprintf(stderr,"erreur fork\n");
  else if(d == 0){
    close(tube[0]);
    char *buf = malloc(BUFFER_SIZE);
    ssize_t bufread = read(STDIN_FILENO,buf,BUFFER_SIZE);
    if(bufread != -1){
      write(tube[1],buf,bufread);
    }
    free(buf);
    close(tube[1]);
  }
  else{
    close(tube[1]);
    int fd = open("file.txt",O_WRONLY);
    char *buf = malloc(BUFFER_SIZE);
    ssize_t bufread = read(tube[0],buf,BUFFER_SIZE);
    if(bufread != -1){
      write(fd,buf,bufread);
    }
    close(fd);
    close(tube[0]);
    free(buf);
  } 
}

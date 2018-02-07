#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>




#define CHK(X) do if ((X) == -1) {perror(#X);exit(EXIT_FAILURE);} while(0)
#define SIZE 4
#define DONNEES "./donnees"


int main (int argc, char** argv) 
{
  char buf[SIZE];
  int fd, newfd; //file descriptor
  int size;
  dev_t dev = 0;
  CHK(fd = open(DONNEES,O_RDONLY));
  CHK(size = read(fd,buf,SIZE));
  CHK(write(STDOUT_FILENO,buf,size));

  #ifdef DUP
  CHK( newfd = dup(fd));

  #else 
  CHK(newfd = open(DONNEES,O_RDONLY));

  #endif

  CHK(size = read(newfd,buf,SIZE));
  CHK(write(STDOUT_FILENO,buf,size));
  close(newfd);
  close(fd);
  return EXIT_SUCCESS;
 }

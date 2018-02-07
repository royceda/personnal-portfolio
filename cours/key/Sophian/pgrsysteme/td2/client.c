#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define CHK(X) do if ((X) == -1) {perror(#X);exit(EXIT_FAILURE);} while(0)
#define FIFO "./versserveur"
#define SIZE 200


int main (int argc, char** argv) 
{
  char buf[SIZE];
  int fd; //file descriptor
  dev_t dev;

  CHK(fd = open(FIFO,O_WRONLY));
  int n = 1;
  while(n>0) {
    CHK(n = read(STDIN_FILENO,buf,SIZE));
    CHK(write(fd,buf,n));
  }
  return EXIT_SUCCESS;
}

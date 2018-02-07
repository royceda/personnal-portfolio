#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define CHK(X) do if ((X) == -1) {perror(#X);exit(EXIT_FAILURE);} while(0)
#define OUT "./in"
#define IN "./out"
#define BUFSIZE 200


int main (int argc, char** argv) 
{
  char buf[BUFSIZE];
  int fd, in, out,n; //file descriptor
  dev_t dev;

  CHK( in = open ( IN , O_RDONLY) ) ;
  CHK( out = open (OUT, O_WRONLY) ) ;

  do {
    CHK(n = read (STDIN_FILENO, buf , BUFSIZE ) ) ;
    if (n>0) write ( out , buf , n ) ;
    CHK(n = read ( in , buf , BUFSIZE ) ) ;
    if (n>0) write (STDOUT_FILENO, buf , n ) ;
  } while (n>0);


  return EXIT_SUCCESS;
}


  /* CHK(fd = open(FIFO,O_WRONLY)); */
  /* int n = 1; */
  /* while(n>0) { */
  /*   CHK(n = read(STDIN_FILENO,buf,SIZE)); */
  /*   CHK(write(fd,buf,n)); */
  /* } */

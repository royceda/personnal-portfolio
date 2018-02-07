#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


#define CHK(X) do if ((X) == -1) {perror(#X);exit(EXIT_FAILURE);} while(0)
#define IN "./in"
#define OUT "./out"
#define BUFSIZE 50


int main (int argc, char** argv) 
{
  char buf[BUFSIZE];
  int fd; //file descriptor
  int size, in, out,n, numread;
  dev_t dev = 0;

  system("rm -f ./in");
  system("rm -f ./out");
  CHK(mknod(IN,S_IFIFO | 0666,dev));
  CHK(mknod(OUT,S_IFIFO | 0666,dev));
  CHK( in = open(IN, O_RDONLY));
  CHK( out = open(IN, O_WRONLY));

  do {
    CHK(n = read ( in , buf , BUFSIZE ) ) ;
    if (n>0) write (STDOUT_FILENO, buf , n ) ;
    CHK(n = read (STDIN_FILENO, buf , BUFSIZE ) ) ;
    if (n>0) write ( out , buf , n ) ;
  }  while (n>0);

   /* while(numread!=0){ */
   /*  numread = read(fd,buf,BUFSIZE); */
   /*  if(numread > 0) write(STDOUT_FILENO,buf,numread); */
   /* } */
  return EXIT_SUCCESS;
}









  /* while(1) { */
  /*   CHK(fd = open(FIFO,O_RDONLY)); */
  /*   CHK(read(fd,buf,SIZE)); */
  /*   size = strlen(buf); */
  /*   CHK(write(STDOUT_FILENO,buf,size)); */
  /*   close(fd); */
  /* } */

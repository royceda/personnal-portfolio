#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


#define CHK(X) do if ((X) == -1) {perror(#X);exit(EXIT_FAILURE);} while(0)
#define FIFO "./versserveur"
#define SIZE 50


int main (int argc, char** argv) 
{
  char buf[SIZE];
  int fd; //file descriptor
  int size;
  dev_t dev = 0;

  system("rm -f ./versserveur");
  CHK(mknod(FIFO,S_IFIFO | 0666,dev));
  while(1) {
    CHK(fd = open(FIFO,O_RDONLY));
    CHK(read(fd,buf,SIZE));
    size = strlen(buf);
    CHK(write(STDOUT_FILENO,buf,size));
    close(fd);
  }

   while(numread!=0){
    numread = read(fd,buf,MAX_BUF_SIZE);
    if(numread > 0) write(STDOUT_FILENO,buf,numread);

  return EXIT_SUCCESS;
}

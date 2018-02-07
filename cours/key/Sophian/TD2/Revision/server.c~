#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define CHK(X) do if ((X) == -1) {perror(#X);exit(EXIT_FAILURE);} while(0)
#define FIFO "./server1"
#define SIZEBUF 10




int main(){

  system("rm server1");
  ssize_t size;
  int rt ;
  dev_t dev = 0;
  char buf[SIZEBUF];
  int fd;
  CHK(mknod(FIFO, S_IFIFO | 0666,dev));

  while(1){
    CHK(fd = open(FIFO, O_RDONLY));
    CHK(size = read(fd, buf, SIZEBUF));
    CHK(rt = write(STDOUT_FILENO, buf, size));
    close(fd);
  }


  return 0;
}

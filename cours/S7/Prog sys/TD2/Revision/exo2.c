#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define CHK(X) do if ((X) == -1) {perror(#X);exit(EXIT_FAILURE);} while(0)
#define SIZE 4

void main1(){
  
  int fd;
  ssize_t size;
  int rd = 0;
  char buf[SIZE];

  CHK( fd = open("data", O_RDONLY));
  CHK( size = read(fd, buf, SIZE));
  
  // printf("lu: %s\n", buf);
  CHK( write(STDOUT_FILENO, buf, rd));

  close(fd);
}


void main2(){

  int fd;
  int dd;
  int rd;
  char buf[SIZE];

  CHK( fd = open("data", O_RDONLY));
    
  dd = dup(fd);
  printf(" file descriptor:\n dd: %d \n fd: %d\n",dd, fd);


  CHK(  rd = read(dd, buf, SIZE));
  CHK(  write(STDOUT_FILENO, buf, rd));

  printf("\n");
}


void main3(){

  int fd;
  int dd;
  int rd;
  char buf[SIZE];

  CHK( fd = open("data", O_RDONLY));
    
  dd = open("data", O_RDONLY);
  printf(" file descriptor:\n dd: %d \n fd: %d\n",dd, fd);


  CHK(  rd = read(dd, buf, SIZE));
  CHK(  write(STDOUT_FILENO, buf, rd));

  printf("\n");
}


int main() {
  //  main1();
  main2();
  main3();
  return 0;
}

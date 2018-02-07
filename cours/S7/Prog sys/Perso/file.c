#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>



void creation() {

  int fd = creat("aaa.txt", O_EXCL);
  if( fd == -1) {
    fd = open("aaaa.txt", O_TRUNC);
    if( fd == -1){
      perror("open");
      exit(1);
    }
    perror("creat");
  }

  char* buf = malloc(32*sizeof(char));
  strcpy(buf,"bonjour Royce");

  int fdw = write(fd, buf, sizeof(buf));
  if( fdw == -1){
    perror("write");
    exit(1);
  }
  fd = close(fd);
  if( fd == -1){
    perror("close");
    exit(1);
  }
}



void lecture() {

  int fd = open("file.c", O_RDONLY);
  if( fd == -1)
    perror("open");

  char *buf = malloc(32*sizeof(char));
  ssize_t S = read(fd, buf, 128);
  
  printf("taille: %d \n %s \n", S,buf);

  fd = close(fd);
  if( fd == -1)
    perror("close");
}


void repertoire() {

  struct dirent *pDIR = malloc(sizeof(struct dirent));
   pDIR = opendir("../");
  if (pDIR == NULL) {
    perror("opendir() failed");
    exit(1);
  }

  struct dirent *pDIRent = readdir(pDIR);
  while(pDIRent != NULL) {
    printf("%s\n",pDIRent->d_name);
    pDIRent = readdir(pDIR);
  }

  closedir(pDIR);
}

int main() {
  creation();
  lecture();
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define READ_MAX 1000

int identique(int fd1, int fd2){
  int r1,r2;
  int n1,n2;
  char *b1 = malloc(READ_MAX);
  char *b2 = malloc(READ_MAX);
  r1 = read(fd1,b1,READ_MAX);
  r2 = read(fd2,b2,READ_MAX);
  if(r1 == r2){
    //for(int i=0; i<r1; i++){
      if(strcmp(b1,b2)){
	printf("different\n");
	return EXIT_SUCCESS;
      }
      //}
    printf("identique\n");
  }
  else{
    printf("different\n");
    return EXIT_SUCCESS;
  }
  return EXIT_SUCCESS;
}

int main(int argc, char **argv){
  int fd1 = open(argv[1],O_RDONLY);
  
  
  printf("fichier %s et entrée standard: ", argv[1]);
  identique(fd1,STDIN_FILENO);
  
  return EXIT_SUCCESS;
}

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(int ahc, char **argv){
  int desc = -1;
  
  desc = open("./monfichier.txt",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
  fprintf(stdout,"index desc (toto): %i\n", desc);
  close(desc);
  exit(EXIT_SUCCESS);
}


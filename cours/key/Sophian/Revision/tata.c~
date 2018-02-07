#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>


int main(int ahc, char **argv){
  int desc = -1;
  
  desc = open("./monfichier2.txt",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
  fprintf(stdout,"index desc (tata): %i\n", desc);
  fflush(stdout);
  execlp("./toto","toto",NULL);
  exit(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

int main(int argc, char *argv[]){
  ssize_t retour;
  ssize_t retour2;
  int i;
  size_t len;
  long w = 5;
  retour = write(STDOUT_FILENO, &w,sizeof(long));
      if(retour == -1){
        	perror("write");
        	return EXIT_FAILURE;
      }
      else if (retour != sizeof(long) ){
        	fprintf(stderr, "%ld n'a pas ete ecrit en entier \n",w);
        	return EXIT_FAILURE;
      }
  retour2 = write(STDOUT_FILENO, &retour,sizeof(ssize_t));
      if(retour == -1){
        	perror("write");
        	return EXIT_FAILURE;
      }
      else if (retour2 != sizeof(ssize_t )){
        	fprintf(stderr, "%zd n'a pas ete ecrit en entier \n",retour);
        	return EXIT_FAILURE;
      }
  return EXIT_SUCCESS;
}
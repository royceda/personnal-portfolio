#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>


int main(int argc, char *argv[]){
  ssize_t retour;
  size_t len = 256;
  long buf;
  retour = read(STDIN_FILENO, &buf,sizeof buf);
  if(retour == -1){
    perror("read");
    return EXIT_FAILURE;
  }
  else if (retour != len ){
    fprintf(stderr, "%d n'a pas ete lu en entier \n",buf);
    return EXIT_FAILURE;
  }  

return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

int main(int argc, char *argv[]) {
  long valeur;
  ssize_t retour, r;
  
  retour = read(STDIN_FILENO, &valeur, sizeof(valeur));
  //A propos de du read()
  if (retour == -1) 
    {
      perror("read");
      return EXIT_FAILURE;
    } 
  else if (retour != sizeof(valeur)) 
    {
      fprintf(stderr, "valeur n'a pas ete lue en entier\n");
      return EXIT_FAILURE;
    } 
  else if (retour == 0) /* EOF */
    return EXIT_SUCCESS;
  


  r = read(STDIN_FILENO, &retour, sizeof retour);
  //A propos du read 
  if (r == -1) 
    {
      perror("read");
      return EXIT_FAILURE;
    } 
  else if (r != sizeof retour) 
    {
      fprintf(stderr, "retour n'a pas ete lue en entier\n");
      return EXIT_FAILURE;
    } 
  else if (r==0) /* EOF */
    return EXIT_SUCCESS;
  
  printf("valeur: %ld \t retour: %ld\n",valeur,(long) retour);
  
  return EXIT_SUCCESS;
}

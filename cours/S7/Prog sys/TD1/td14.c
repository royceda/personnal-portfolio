#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[]) {

  long valeur = 5;

  size_t ret = write(STDOUT_FILENO, &valeur, sizeof valeur);
  ret = write(STDOUT_FILENO, &ret, sizeof ret); 


  return EXIT_SUCCESS;
}

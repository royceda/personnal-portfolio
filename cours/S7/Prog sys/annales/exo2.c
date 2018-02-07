#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int aleatoire() {
  float max = 3;
  int nombre = (int)(max*rand() / RAND_MAX);
  return (nombre);
}

void f() {
  printf("A\n");
  exit(EXIT_SUCCESS);
}

void g() {
  printf("S\n");
  exit(EXIT_SUCCESS);  
}


int main() {

  srand(time(NULL));
  signal(SIGALRM, f);
  signal(SIGUSR1, g);
 
  alarm( 10);  
  sleep( 1);
 

  kill(getpid(), SIGUSR1);
  exit(EXIT_SUCCESS);
  return 0;
}

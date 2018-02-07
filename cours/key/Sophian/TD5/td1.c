#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


struct sigaction sa;
sa.sa_handler = handler;
sigemptyset(&sa.sa_mask);
sa.sa_flags = 0;
sigaction(SIGUSR1, &sa, NULL);



void handler(int signum) {
  
  printf("%ld received signal %d\n",(long)getpid(), signum);
}


int main() {
  
  printf("pid %ld \n", (long)getpid());
  signal(SIGUSR1, handler);
  pause();
  signal(SIGUSR1, SIG_DFL);
}


// probleme ici le code n'est pas super portable, ce n'est plus trop utilisé
// cf sigaction 

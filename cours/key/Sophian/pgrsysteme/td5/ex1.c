#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void myhandler(int signum){
  fprintf(stderr, "%d : i received the singal %d \n", getpid(), signum);
}

int main(int argc, char *argv[])
{

  struct sigaction my_action, old_action;
  printf(" pid %u \n ", getpid());


  my_action.sa_handler = myhandler;
  sigemptyset(&my_action.sa_mask);
  my_action.sa_flags = 0;

  //sigaction( SIGUSR1, myhandler);
  sigaction(SIGUSR1, &my_action, &old_action);
  pause();
  
  //sigaction( SIGUSR1, SIG_DFL);
  sigaction( SIGUSR1, &old_action, NULL);
  return EXIT_SUCCESS;



}

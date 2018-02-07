#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#include <fcntl.h>           /* For O_* constants */
#include <semaphore.h>
#include <sched.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 7000
#define CHK(X) if((X) == -1) {perror(#X); exit(1);}


int main(int argc, char *argv[]) {

  int port = PORT;
  //int so = socket( AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in server;

  if(argc == 2)
    port = atoi(argv[1]);
  int s;
  CHK( s=socket(AF_INET, SOCK_STREAM,0));
  
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(port);
  
  CHK(bind(s, (struct sockaddr *)&server, sizeof(server)));
  printf("socket port: %d\n", ntohs(server.sin_port));
  
  //lecoute
  CHK(listen(s, 8));
  //accepte la connexion
  int s2;
  CHK(s2 = accept(s,0,0));
  printf("connection accepted ..... \n");
  getchar();
  printf("connection accepted Closing..... \n");


  //telnet localhost 7000
  close(s2);
  close(s);
          
  return 0;
}

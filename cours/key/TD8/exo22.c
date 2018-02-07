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


#define BUFSIZE 32
#define PORT 7000
#define CHK(X) if((X) == -1) {perror(#X); exit(1);}


void *echo(void *arg ){
  int n;
  char buffer[BUFSIZE];
  while(1){
    n = read(ret, buffer, BUFSIZE);
    if( strstr(buffer, "quit"))
      break;
    write(ret, buffer, n);
  }
  return NULL;
}

static int s;

void handler(int sig){
  close(s);
}


int main(int argc, char *argv[]) {

  int port = PORT;
  struct sockaddr_in server;
  struct sigaction sa;
  int fils = 0;
  

  if(argc == 2)
    port = atoi(argv[1]);
  
 
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

  /*
  //traitant
  sa.sa_handler = handler;
  sigemtyset(&sa.sa_mask);
  sa.sa_flags = 0;
  sigaction(SIGINT, &sa, NULL);
  */

  int fini = 0;
  while(1){
    pthread th;
    s2 = accept(s,0,0);
    if(s2<0) {
      perror("accept");
      if(fini)
	break;
    }
    th = pthread_create(&th, echo, (void*)(intptr_t)s2);
  
  if(th){
      /*pere*/
      close(s2);
    }

    else
      {//fils
	close(s);       
	echo(s2);
	printf("connexion accepted\n");
	close(s2);
	exit(1);
      }

    echo(s);
    printf("connection accepted ..... \n");
    close(s2);
  }  


  //telnet localhost 7000
  close(s);          
 
  while(fils) {
    wait(NULL);
    printf("fils terminé\n");
    fils--;
  }

 return 0;
}

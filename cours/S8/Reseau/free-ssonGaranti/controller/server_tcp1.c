#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <netdb.h>
#include <sys/select.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include "poisson.h"
#include "tool.c"
#include "graphe.h"


#define BUFSIZE 2048
#define PORT port_number()
#define CHK(X) if((X) == -1) {perror(#X); exit(1);}


Agraph_t *graph = NULL;
struct aquarium *aqua_tmp ;

char* getLabelBySocket(int sock){
  char socket[4];
  char* label = malloc(10*sizeof(char));
  int i = 0;
  sprintf(socket,"%d", sock);
  while(i<LIMIT && binder[1][i] != NULL){
    if(strcmp(binder[1][i], socket) == 0){
      label = binder[0][i];
    }
  }
  return label;
}

void delBindSocket(int sock){

 int n = graphSize(graph);
 char socket[4];
 sprintf(socket, "%d", sock);
  int i=0;
  while(i<n){
    if(strcmp(binder[1][i], socket) == 0){
      binder[1][i] = NULL;
      i = n;
    }
  }
}

void addBindSocket(int sock){

  int n = LIMIT;
  int i=0;
  char socket[8];
  while(i<n){
    if(binder[0][i] == NULL)
      i = n;
    else if(binder[1][i] == NULL){
      sprintf(socket, "%d", sock);
      binder[1][i] = socket;
      i = n;
    }
    else
      i++;
  }
}


int port_number(){
  FILE* config_file = fopen("../bin/controller.cfg", "r");
  if (config_file == NULL) {
    fprintf(stderr, "file not found\n");
  } else {
    int port;
    if(fscanf(config_file, "controller-port = %d\n", &port) == 1){
      fprintf(stderr, "Found port number in config, it's %d\n", port);
    } else {
      fprintf(stderr,"No port found\n");
    }
    return port;
  }
  return -1;
}


char* create_message(char *buffer, int fd){
  char temp[BUFSIZE];
  itoa(fd, temp);
  //sprintf(buffer, "%s %d", buffer, fd);
  strcat(buffer, temp);
  return buffer;
}


char* get_date_string(){
  char *date1 = malloc(BUFSIZE);
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  sprintf(date1, "at: %d-%d-%d %d:%d:%d\n" , tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  return date1;
}


void* refresh_handler(void *socket){
  //Get the socket descriptor
  int sock = *(int*)socket;
  fprintf(stderr, "sock weedhand :%d\n", sock);

  char *message, server_message[BUFSIZE];

  fd_set fdset;
  FD_SET(sock , &fdset);

  sprintf(server_message, "client: %d reception: OK\n", sock);

  //Send some messages to the client
  message = " Refresh thread: OK\n";
  write(sock , message , strlen(message));
  write(sock, get_date_string(), strlen(get_date_string()));

  char *refresh = "refresh";

  while(1){
    write(sock, refresh, strlen(refresh));
    char *message = getFishes("N1"/* getLabelBySocket(sock) */, aqua_tmp);
    write(sock , message , strlen(message));
    sleep(1);
   }
  return 0;
}


void *weed_handler(void *socket_desc){
  //Get the socket descriptor
  int sock = *(int*)socket_desc;
  int fresh = 0;
  fprintf(stderr, "sock weedhand :%d\n", sock);
  int read_size;
  char *message, client_message[BUFSIZE], server_message[BUFSIZE];
  pthread_t refresh_th;

  sprintf(server_message,"client: %d reception: OK\n", sock);

  //Send some messages to the client
  message = " thread: OK\n";

  write(sock , message, strlen(message));

  message = "aquarium is loading  \n";
  write(sock , message , strlen(message));

  //reception du client
  while( (read_size = recv(sock , client_message , BUFSIZE , 0)) > 0 ){

    //traitement du graphes
    create_message(client_message, sock);
    //fin de la chaine
    //client_message[read_size] = '\0';
    printf("%s \n", client_message);

    write(sock, client_message , strlen(client_message));
    printf(" client %d \n", sock);
    write(STDOUT_FILENO, server_message , strlen(server_message));


    //lecture des commandes => appel dans la lib poisson.c
    /*
    AddFish
    delFish
    getFishes
    startFish
    getFishesContinuously
    reception exit => socketclose !
    */



    if (!strncmp(client_message, "addFish", 7)){
      printf("getLabelBySocket = %s\n ", getLabelBySocket(sock));
      //concat
      sprintf( client_message, "%s %s", client_message, getLabelBySocket(sock));
      addFish(client_message, aqua_tmp);

      fprintf(stderr,"addfish OK\n");
      fprintf(stderr, "%s", get_date_string());


    }
    else if (!strncmp(client_message,"delFish", 7)){

      if (delFish(client_message, aqua_tmp) == 0){
        fprintf(stderr,"delfish OK\n");
        fprintf(stderr, "%s", get_date_string());
        write(sock , "delfish OK\n" , 11);
      }
      else
      fprintf(stderr,"NOK\n");
      fprintf(stderr, "%s", get_date_string());
      write(sock , "delfish NOK\n" , 12);
    }

    else if (!strncmp(client_message, "startFish", 9)){

      if (startFish(client_message, aqua_tmp) == 1){
        fprintf(stderr,"startfish OK\n");
        fprintf(stderr, "%s", get_date_string());
        write(sock , "startfish OK\n" , 13);
      }
      else
      fprintf(stderr,"startfish NOK\n");
      fprintf(stderr, "%s", get_date_string());
    }
    else if (!strncmp(client_message, "getFishesContinuously", 21 )){
      fprintf(stderr,"getFishesContinuously OK\n");
      fprintf(stderr, "%s", get_date_string());

      if( pthread_create( &refresh_th , NULL ,  refresh_handler , (void*) &sock) < 0){
        perror("could not create refresher thread");
        return NULL;
      }
      else {
        //Now join the thread , so that we dont terminate before the thread
        fresh = 1;
        printf("Refresher Handler OK!\n");
        fprintf(stderr, "%s", get_date_string());
      }

    }
    else if (!strncmp(client_message, "getFishes", 9)){
      fprintf(stderr,"getFishes\n");
      fprintf(stderr, "%s", get_date_string());
      printf("getLabelBySocket = %s\n ", getLabelBySocket(sock));
      char *message = getFishes( getLabelBySocket(sock), aqua_tmp);
      write(sock , message , strlen(message));
    }
    else if (!strncmp(client_message, "status", 6)){ //pb avec client
      fprintf(stderr,"status\n");
      fprintf(stderr, "%s", get_date_string());
      char* status_tmp = status( getLabelBySocket(sock) , aqua_tmp);
      write(sock , status_tmp, strlen(status_tmp));
    }

    else if (!strncmp(client_message, "hello", 5)){
      fprintf(stderr,"Hello Darius, tu paye ta binouze :D\n");
      fprintf(stderr, "%s", get_date_string());


    }
    else if (!strncmp(client_message, "exit", 4)){

      fflush(stdout);
      close(sock);
      write(sock, "BYE", strlen("BYE"));
      //pthread_join(refresh_th , NULL);
      if(fresh == 1){
        pthread_kill(refresh_th, 0);//seg fault possible
      }
        //delBindSocket(sock);
        fprintf(stderr, "Client disconnected %d\n", sock);
        fprintf(stderr, "%s", get_date_string());
        break;
  }

    else{
      fprintf(stderr, "%s", get_date_string());
      fprintf(stderr, "Unknown Command\n");
    }


    //envoi des infos au client
    /*  for(int i = 0; i <3; ++i){
    strcpy(buffer, "> getFishesContinuously\n
    < list [PoissonRouge at 92x40,10x4,5] [PoissonClown at 22x80,12x6,5]\n
    < list [PoissonRouge at 91x41,10x4,5] [PoissonClown at 21x80,12x6,5]\n
    < list [PoissonRouge at 92x43,10x4,5] [PoissonClown at 23x80,12x6,5]\n");

	  write(sock, buffer , strlen(buffer));
	  }*/

    //RAZ du message
    memset(client_message, 0, BUFSIZE);
  }

  //verification de deconnection
  /*
  if(read_size == 0){
  fprintf(stderr, "Client disconnected %d\n", sock);
  fflush(stdout);
  close(sock);
}
else */
if(read_size == -1){
  perror("recv failed");
}
return 0;
}


//modification du handler pour la suite
void *connection_handler(void *socket_desc){
  //Get the socket descriptor
  int sock = *(int*)socket_desc;
  int read_size;
  char *message , client_message[BUFSIZE], server_message[BUFSIZE];

  sprintf(server_message,"client: %d\n reception: OK\n", sock);

  //Send some messages to the client
  message = " thread: OK\n";
  write(sock , message , strlen(message));

  message = "ecrit un truk  \n";
  write(sock , message , strlen(message));

  //reception du client
  while( (read_size = recv(sock , client_message , BUFSIZE , 0)) > 0 )    {
    //fin de la chaine
    client_message[read_size] = '\0';

    //envoi du message au client
    write(sock , client_message , read_size);
    printf(" client %d \n", sock);
    write(STDOUT_FILENO , server_message , strlen(server_message));

    //RAZ du message
    memset(client_message, 0, BUFSIZE);
  }

  if(read_size == 0){
    fprintf(stderr, "Client disconnected %d\n", sock);
    close(sock);
  }
  else if(read_size == -1){
    perror("recv failed");
  }

  return 0;
}

void* graph_handler(){
  controle_graph(graph);
  return 0;
}



//telnet localhost port
int main(){
  aqua_tmp = new_aquarium(graph);
  printf("initialisation de l'aquarium");
  int sockfd, newsockfd, clilen;
  pthread_t thread_id, graph_th;
  struct sockaddr_in serv_addr, cli_addr;


  //on utilise IP
  sockfd = socket( AF_INET, SOCK_STREAM, 0);
  CHK( sockfd )

  bzero( (char*)&serv_addr, sizeof(serv_addr));

  serv_addr.sin_family      = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port        = htons(PORT);

  // bind
  CHK( bind( sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) <0);

  //file dattente de taille: 5
  listen(sockfd, 5);

  clilen = sizeof(cli_addr);

  if( pthread_create( &graph_th , NULL ,  graph_handler , NULL )< 0){
    perror("could not create graph thread");
    return 1;
  }
  else {
    //Now join the thread , so that we dont terminate before the thread
    printf("Graph Handler OK!\n");
  }


  while( (newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen)) )    {

    addBindSocket(newsockfd);

    printf("Connection accepted %d\n", newsockfd);

    if( pthread_create( &thread_id , NULL ,  weed_handler , (void*) &newsockfd) < 0){
      perror("could not create thread");
      return 1;
    }
    else {
      //Now join the thread , so that we dont terminate before the thread
      printf("%s\n", get_date_string());
      printf("Handler OK!\n");
    }

  }
  pthread_join(thread_id , NULL);

  close(sockfd);
  return 0;
}

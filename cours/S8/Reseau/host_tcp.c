#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>



void error(char *msg){
  perror(msg);
  exit(1);
}



int main(int argc, char *argv[]){

  int sockfd, newsockfd, portno, n;
  char buffer[256];

  struct sockaddr_in serv_addr;
  struct hostent *server;

  if(argc < 3){
    fprintf(stderr, "ERROR, no port provided\n");
    exit(1);
  }

  portno = atoi(argv[2]);


  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if(sockfd < 0)
    error("error: opening socket");



  server = gethostbyname(argv[1]);
  
  if(server == NULL){
    fprintf(stderr, "error: no host\n");
    exit(0);
  }


  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  /*  bcopy((char *)server->h_addr, 
  	(char *)&serv_addr.sin_addr.s_addr, 
  	server->h_length);
  */

  serv_addr.sin_port = htons(portno);

  if( connect(sockfd, &serv_addr, sizeof(serv_addr)) < 0)
    error("error: connecting");

  printf("ecrire un message\n");
  bzero(buffer, 256);
  fgets(buffer,255, stdin);
  n = write(sockfd, buffer, strlen(buffer));
  if(n <0)
    error("error:writing");

  bzero(buffer, 256);
  
  n = read(sockfd, buffer, 255);
  
  if(n < 0)
    error("error: reading from socket");
  
  printf("%s\n", buffer);
    
  return 0;
}

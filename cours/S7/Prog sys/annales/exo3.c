#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


/*genere un nombre entre 0 et 9*/

int aleatoire(){
  srand(time(NULL)+getpid());
  float max = 10;
  int nombre = (int)(max*rand()/RAND_MAX);
  return (nombre);
}

int calculer(){
  int alea = aleatoire();
  printf("init  = %d\n\n",alea);
  int i;
  if(alea<5){
    int m[2];
    pipe(m);
    for(i=0; i<2; ++i){
      int r;
      if ((r = fork()) < 0){perror("fork()");exit(1);}
      if (r==0){
	close(m[0]);
	int alea2 = calculer();
	printf("ecriture = %d \n", alea2);
	write(m[1], &alea2, sizeof(int));
	close(m[1]);
	exit(EXIT_SUCCESS);
      }
    }

    close(m[1]);
    for(i=0; i< 2; ++i){
      int lu;
      read(m[0], &lu, sizeof(int));
      alea += lu;
      printf("lecture = %d \n", alea);
    }
    close(m[0]);
    for( i=0; i<2; ++i){
      int status;
      wait(&status);
    }
  }
  return alea;
}





int main(int argc, char *argv[]){
  printf("resultat: %d\n", calculer());
  exit(EXIT_SUCCESS);
}



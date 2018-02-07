#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>



#define CHAINE1 "DEBUT "
#define CHAINE2 "FIN "


int main(int argc, char *argv[])
{
  //I
  int out1 = STDOUT_FILENO;
  FILE *fout1 = stdout;
  
#ifdef UTILISER_SORTIE_ERREUR1
  out1 = STDERR_FILENO;
  fout1 = stdout;
#endif
 
#ifdef UTILISER_FPRINTF1
 fprintf(fout1, CHAINE1);
#else
 write(out1, CHAINE1,strlen(CHAINE1));
#endif
 sleep(3);



 //II
  int out2 = STDOUT_FILENO;
  FILE *fout2 = stdout;
  
#ifdef UTILISER_SORTIE_ERREUR2 //Pas bufferiser
  out2 = STDERR_FILENO;
  fout2 = STDERR;
#endif

 
#ifdef UTILISER_FPRINTF2
 fprintf(out2, CHAINE2);
#else
 write(out2, CHAINE2, strlen(CHAINE2));
#endif
 sleep(3);


#ifdef UTILISER__EXIT
 _exit(0);
#else
 exit(0);
#endif


 //isotty(fd) (file descripteur)

 return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define CHAINE1 "hello world\n"
#define CHAINE2 "okokok\n"


int main() {

  FILE *out1  = stdout;
  int fout1 = STDOUT_FILENO; //file descriptor out

#ifdef UTILISER_SORTIE_ERREUR1
  out1 = stderr;
  fout1 = STDERR_FILENO;
#endif

#ifdef UTILISER_FPRINTF1
  fprintf(out1, CHAINE1);
#else  
  write(fout1, CHAINE1, sizeof(CHAINE1));
#endif
  sleep(3);


  FILE *out2 = stdout;
  int fout2 = STDOUT_FILENO;


#ifdef UTILISER_SORTIE_ERREUR2
  out2 = stderr;
  fout2 = STDERR_FILENO;
#endif



#ifdef UTILISER_FPRINTF2
  fprintf(out2, CHAINE2);
#else
  write(fout2, CHAINE2, sizeof(CHAINE2));
#endif


#ifdef UTILISER__EXIT
  _exit(0);
#else 
  exit(0);
#endif

  return 0;
}

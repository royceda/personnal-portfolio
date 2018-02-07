#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#define CHAINE1 "a"
#define CHAINE2 "b \n"

int main (int argc, char** argv) 
{
#ifdef UTILISER_FPRINTF1
# ifdef UTILISER_SORTIE_ERREUR1
   fprintf(stderr, CHAINE1 );
# else
  fprintf(stdout, CHAINE1 );
# endif

#else 
# ifdef UTILISER_SORTIE_ERREUR2
  write(STDERR_FILENO, &CHAINE1,sizeof(CHAINE1));
# else
  write(STDOUT_FILENO, &CHAINE1,sizeof(CHAINE1));
# endif
#endif

  sleep(5);

#ifdef UTILISER_FPRINTF2
# ifdef UTILISER_SORTIE_ERREUR1
   fprintf(stderr, CHAINE2);
# else
  fprintf(stdout, CHAINE2);
# endif

#else 
# ifdef UTILISER_SORTIE_ERREUR2
  write(STDERR_FILENO, &CHAINE2,sizeof(CHAINE2));
# else
  write(STDOUT_FILENO, &CHAINE2,sizeof(CHAINE2));
# endif
#endif

 
  return EXIT_SUCCESS;
}

#ifndef PS_STANDARD_H 
#define PS_STANDARD_H 

#include <stdbool.h>

struct autobus;
struct ps_standard;

struct ps_standard *ps_std_creer(char *, long);
void ps_std_liberer(struct ps_standard *);

void ps_std_monter_dans(struct ps_standard *, struct autobus *);

bool ps_std_est_dehors(const struct ps_standard *);
bool ps_std_est_assis(const struct ps_standard *);
bool ps_std_est_debout(const struct ps_standard *);
char *ps_std_nom(const struct ps_standard *);

#endif //PS_STANDARD_H 

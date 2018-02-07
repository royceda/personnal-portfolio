void *malloc(int);

int main() {
  int *tab = malloc(4*4);
  int i;
  for(i=0; i<=4; i++)
    tab[i] = 1;

  return 0;
}

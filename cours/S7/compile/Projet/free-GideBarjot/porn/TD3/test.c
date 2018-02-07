#include <stdio.h>
#include <stdlib.h>

#define N 16

int calculscal (int n,int m) {
  int z;
  z=n*n+20;
  return z;
}

void calcularray (float *a, float *b) {
  int i;
  for (i=0; i<N; i++) {
    a[i]+=b[i];
  }
}

int main() {
  int i;
  int a,b;
  float *c,*d;
  a=13;
  b=27;
  c= (float *)malloc(sizeof(float)*N);
  d= (float *)malloc(sizeof(float)*N);
  for (i=0; i<N; i++) { d[i]=i; c[i]=N-i; }
  printf("%d\n", calculscal(a,b));
  calcularray(c,d);
  for (i=0; i<N; i++)
    printf("%f ",c[i]);
  return 0;
}

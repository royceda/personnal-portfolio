#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

//Use for itoa
void mirror(char *str){
    int l = strlen(str);
    int m = l / 2; // meme remarque
    int i = 0;
    char tmp;
    while (i < m) {
        tmp = str[i];
        str[i] = str[l - i - 1];
        str[l - i - 1] = tmp;
        i = i + 1;
    }
}

void itoa(int val, char *dst) {
    int i = 0;
    int neg = val < 0;

    if(neg){ // Sinon le modulo est negatif
        val = - val;
    }
    do {
        dst[i] = (val % 10) + '0';
        val = val / 10;
        i = i + 1;
    } while (val);

    if (neg) { // cas particulier pour le signe
        dst[i] = '-';
        i = i + 1;
    }
    dst[i] = 0;
    mirror(dst);
}
void DelSpace(char* str)
{
  char c, *p;

	p = str;
	do
	  while ((c = *p++) == ' ' || (c == '\n')) ;
	while ((*str++ = c));
	return;
}



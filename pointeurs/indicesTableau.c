#include<stdio.h>
#define N 26

int main()
{
  char t[N];
  char v = 'A';
  char* p;
  int i;
  p = t;

  /* initialisation du tableau*/
  for (i = 0 ; i < N ; i++)
    *(p + i) = v++;

  /* affichage du tableau*/
  for(i = 0 ; i < N ; i++)
    printf("%c ", *(p + i));

  printf("\n");
  return 0;
}

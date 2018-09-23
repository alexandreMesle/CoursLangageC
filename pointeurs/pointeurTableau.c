#include<stdio.h>

main()
{
  char t[10];
  char* p;
  t[1] = 'b';
  p = t;
  printf("le deuxieme element du tableau est %c.\n", *(p+1));
}

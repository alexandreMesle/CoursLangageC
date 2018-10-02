#include<stdio.h>

int main()
{
  char t[10];
  char* p;
  t[0] = 'a';
  p = t;
  printf("le premier element du tableau est %c.\n", *p);
  return 0;
}

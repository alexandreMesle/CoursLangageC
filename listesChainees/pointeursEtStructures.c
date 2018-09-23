#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct 
{
  int i;
  char c;
}st;

int main()
{
  st* p;
  p = (st*)malloc(sizeof(st));
  p->i = 5;
  p->c = 'a';
  printf("p = (%d, %c)\n", p->i, p->c);
  free(p);
  return 0;
}

#include<stdio.h>

void main()
{
  int x = 3;
  int* p;
  p = &x;
  printf("x = %d\n", x);
  *p = 4;
  printf("x = %d\n", x);
}

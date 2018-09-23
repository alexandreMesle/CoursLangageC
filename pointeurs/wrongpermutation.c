#include<stdio.h>

void echange(int x, int y)
{
  int t = x;
  x = y; 
  y = t;
}

void main()
{
  int a = 1;
  int b = 2;
  printf("a = %d, b = %d\n", a, b);
  echange(a, b);
  printf("a = %d, b = %d\n", a, b);
}

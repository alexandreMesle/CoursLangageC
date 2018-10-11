#include<stdio.h>

int main()
{
  int a, b, c, d;
  a = 1; b = 2;
  c = a/b;
  d = (a==b)?3:4;
  printf("c = %d, d = %d\n", c, d);
  a = ++b;
  b %= 3;
  printf("a = %d, b = %d\n", a, b);
  b = 1;
  for(a = 0 ; a <= 10 ; a++)
    c = ++b;
  printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d); 
  return 0;
}

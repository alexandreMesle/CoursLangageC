#include<stdio.h>

int main()
{
  int a = 2, b = 4, c;
  c = (b = a);
  printf("b = %d\n", b);
  printf("c = %d\n", c);
}

#include<stdio.h>

int main()
{
  int x = 3;
  int y = 5;
  int* p;
  p = &x;
  printf("x = %d\n", x);
  *p = 4;
  printf("x = %d\n", x);
  p = &y;
  printf("*p = %d\n", *p);
  *p = *p + 1;
  printf("y = %d\n", y);  
  return 0;
}

#include<stdio.h>
#define N 5

int main()
{
  int a = 1, b = 0;
  while(a <= N)
    b += a++;
  printf("%d, %d\n", a, b);
  return 0;
}

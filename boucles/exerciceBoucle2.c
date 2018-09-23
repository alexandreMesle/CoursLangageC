#include<stdio.h>
#define M 3
#define N 4

int main()
{
  int a, b, c = 0, d;
  for (a = 0 ; a < M ; a++)
    {
      d = 0;
      for(b = 0 ; b < N ; b++)
	d+=b; 
      c += d
    }
  printf("a = %d, b = %d, c = %d, d = %d", a, b, c, d);
  return 0;
}

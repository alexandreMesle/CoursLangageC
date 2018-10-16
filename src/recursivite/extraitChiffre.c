#include<stdio.h>

long extrait(long x, int p)
{
  if (p == 1)
    return x%10;
  return extrait(x/10, p-1);
}

int main()
{
  long n = 65536, i;
  printf("%ld = ", n);
  for (i = 5 ; i >= 1 ; i--)
    printf("%ld", extrait(n, i));
  printf("\n");
  return 0; 
}

#include<stdio.h>

long factorielle(int n)
{
  if (n == 0)
    return 1;
  return factorielle(n - 1) * n;
}

int main()
{
  int i;
  for (i = 0 ; i < 20 ; i++)
    printf("%d! = %ld\n", i, factorielle(i));
  return 0;
}

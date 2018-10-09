#include<stdio.h>

long factorielle(int n)
{
  if (n == 0)
    return 1;
  return n * factorielle(n - 1);
}

int main()
{
  int i;
  for (i = 0 ; i < 20 ; i++)
    printf("%ld\n", factorielle(i));
  return 0;
}

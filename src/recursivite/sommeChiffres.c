#include<stdio.h>

long sommeChiffres(long n)
{
  if (n == 0)
    return 0;
  return sommeChiffres(n/10) + n%10;
}

int main()
{
  long n = 65536;
  printf("sommec(%ld) = %ld\n", n, sommeChiffres(n));
  return 0; 
}

#include<stdio.h>

long nbChiffres(long n)
{
  if (n < 10)
    return 1;
  return nbChiffres(n/10) + 1;
}

int main()
{
  long i;
  for (i = 2 ; i <= 1000000 ; i *= i)
    printf("nbc(%ld) = %ld\n", i, nbChiffres(i));
  return 0; 
}

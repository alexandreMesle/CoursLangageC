#include<stdio.h>

long factorielle(int n)
{
  if (n == 0)
    return 1;
  return factorielle(n - 1) * n;
}

long factorielle_rec_terminale(int n, int r)
{
  if (n == 0)
    return r;
  return factorielle_rec_terminale(n - 1, r * n);
}

int main()
{
  int i;
  for (i = 0 ; i < 20 ; i++)
    printf("%d! = %ld\n", i, factorielle_rec_terminale(i, 1));
  return 0;
}

#include<stdio.h>

long produit(int a, int b)
{
  if (a == 0)
    return 0;
  return produit(a - 1, b) + b;
}

int main()
{
  int i, j = 8;
  for (i = 0 ; i <= 10 ; i++)
    printf("%d * %d = %ld\n", i, j, produit(i, j));
  return 0;
}

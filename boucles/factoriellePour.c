#include<stdio.h>

int main()
{
  unsigned long n, i, res;
  printf("Saisissez un nombre positif : ");
  scanf("%lu", &n);
  res = 1;
  for(i = 1; i <= n ; i++)
    res *= i;
  printf("%lu! = %lu\n", n, res);
  return 0;
}

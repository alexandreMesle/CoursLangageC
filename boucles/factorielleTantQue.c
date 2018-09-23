#include<stdio.h>

int main()
{
  unsigned long n, i, res;
  printf("Saisissez un nombre positif : ");
  scanf("%lu", &n);
  res = 1;
  i = 1;
  while(i <= n)
    res *= i++;
  printf("%lu! = %lu\n", n, res);
  return 0;
}

#include<stdio.h>

int main()
{
  unsigned long n, i, res;
  printf("Saisissez un nombre positif : ");
  scanf("%lu", &n);
  res = 1;
  i = 2;
  if(n != 0)
    do
      {
	res *= i;
	i++;
      }
    while(i <= n);
  printf("%lu! = %lu\n", n, res);
  return 0;
}

#include<stdio.h>

int main()
{
  double b, res;
  unsigned short n;
  printf("Saisissez un nombre reel : ");
  scanf("%lf", &b);
  printf("Saisissez un nombre entier positif : ");
  scanf("%hu", &n);
  printf("%lf^%hu = ", b, n);
  res = 1;
  while(n > 0)
    {
      res *= b;
      n--;
    }
  printf("%lf\n", res);
  return 0;
}

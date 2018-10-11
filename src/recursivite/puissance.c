#include<stdio.h>

long puissance(int b, int exp)
{
  if (exp == 0)
    return 1;
  return b * puissance(b, exp - 1);
}

int main()
{
  int i;
  for (i = 0 ; i < 20 ; i++)
    printf("%ld\n", puissance(2, i));
  return 0;
}

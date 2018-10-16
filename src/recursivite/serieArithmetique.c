#include<stdio.h>

long serie(int n)
{
  if (n == 0)
    return 0;
  return serie(n - 1) + n;
}

int main()
{
  int i;
  for (i = 0 ; i <= 20 ; i++)
    printf("... +  %d = %ld\n", i, serie(i));
  return 0;
}

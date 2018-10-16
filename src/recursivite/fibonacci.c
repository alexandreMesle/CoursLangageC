#include<stdio.h>

long fibonacci(int n)
{
  if (n <= 1)
    return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
  int i;
  for (i = 0 ; 1 ; i++)
    printf("%d -> %ld\n", i, fibonacci(i));
  return 0;
}

#include<stdio.h>

void compteARebours(int n)
{
  if (n >= 0)
    {
      printf("%d\n", n);
      compteARebours(n - 1);
    }
}

int main()
{
  compteARebours(10);
  return 0;
}

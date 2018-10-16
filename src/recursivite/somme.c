#include<stdio.h>

int somme(int a, int b)
{
  if (a == 0)
    return b;
  return somme(a - 1, b + 1);
  // ou bien
  // return somme(a - 1, b) + 1;
}

int main()
{
  printf("%d\n", somme(10, 0));
  return 0;
}

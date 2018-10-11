#include<stdio.h>

int main()
{
  int t[10], i;
  for(i = 0; i < 10 ; i++)
    {
      printf("Saisir un entier : ");
      scanf("%d", t + i);
    }
  for(i = 0 ; i < 10 ; i++)
    printf("%d ", t[i]);
  printf("\n");
  return 0;
}

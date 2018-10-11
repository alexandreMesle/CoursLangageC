#include<stdio.h>

void afficheInt(int j)
{
  printf("%d", j);
}

int main()
{
  int i;
  printf("Veuillez saisir un entier : ");
  scanf("%d", &i);
  afficheInt(i);
  printf("\n");
  return 0;
}

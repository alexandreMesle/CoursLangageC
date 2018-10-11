#include<stdio.h>

void afficheInt(int i)
{
  printf("%d", i);
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

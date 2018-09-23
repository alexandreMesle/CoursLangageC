#include<stdio.h>

void afficheSomme(int a, int b)
{
  printf("%d", a + b);
}

int main()
{
  int i, j;
  printf("Veuillez saisir deux entiers :\na = ");
  scanf("%d", &i);
  printf("b = ");
  scanf("%d", &j);
  printf("a + b = ");
  afficheSomme(i, j);
  printf("\n");
  return 0;
}

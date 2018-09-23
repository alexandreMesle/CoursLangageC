#include<stdio.h>

int main()
{
  int a, b, c;
  printf("Saisissez trois valeurs : \na = ");
  scanf("%d", &a);
  printf("b = ");
  scanf("%d", &b);
  printf("c = ");
  scanf("%d", &c);
  if (a == b || a == c || b == c)
    printf("Il y a des doublons dans les valeurs que vous avez saisies ");
  else
    printf("Vous avez saisi trois valeurs distinctes");
  printf("\n");
  return 0;
}

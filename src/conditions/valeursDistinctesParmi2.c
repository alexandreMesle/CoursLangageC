#include<stdio.h>

int main()
{
  int a, b;
  printf("Saisissez deux valeurs : \na = ");
  scanf("%d", &a);
  printf("b = ");
  scanf("%d", &b);
  if (a == b)
    printf("Vous avez saisi deux fois la meme valeur.");
  else
    printf("Vous avez saisi deux valeurs distinctes.");
  printf("\n");
   return 0;
}

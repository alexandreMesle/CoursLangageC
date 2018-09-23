#include<stdio.h>

int main()
{
  char a;
  printf("Saississez un caractere : ");
  scanf("%c", &a);
  printf("Vous avez saisi la valeur %c, son code ASCII est %d.\n", a, a); 
  return 0;
}

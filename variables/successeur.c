#include<stdio.h>

int main()
{
  char a;
  printf("Saississez un caractere : ");
  scanf("%c", &a);
  a = a + 1;
  printf("Le caractere suivant est %c\n", a);
  return 0;
}

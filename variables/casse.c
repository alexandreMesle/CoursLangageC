#include<stdio.h>

int main()
{
  char a;
  printf("Saississez une minuscule : ");
  scanf("%c", &a);
  printf("Cette lettre a pour majuscule %c.\n", a + 'A' - 'a');
  return 0;
}

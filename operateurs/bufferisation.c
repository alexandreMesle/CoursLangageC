#include<stdio.h>

int main()
{
  char a;
  int i;
  scanf("%c", &a);
  printf("vous avez saisi %c (code ASCII = %d)\n", a, a);
  scanf("%d", &i);
  getchar();
  printf("vous avez saisi %c (code ASCII = %d)\n", a, a);
  scanf("%c", &a);
  getchar();
  printf("vous avez saisi %c (code ASCII = %d)\n", a, a);
  scanf("%c", &a);
  printf("vous avez saisi %c (code ASCII = %d)\n", a, a);
  getchar();
  while((a = getchar()) != '\n')
    {
      printf("Vous avez saisi %c\n", a);
    }
  return 0;
}

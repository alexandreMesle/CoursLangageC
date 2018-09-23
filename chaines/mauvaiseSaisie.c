#include<stdio.h>

#define N 20

int main()
{
  char chaine[N];
  int i;
  printf("Saisissez une phrase :\n");
  gets(chaine);
  for (i = 0 ; chaine[i] != 0 ; i++)
    printf("chaine[%d] = %c (code ASCII : %d)\n", i, chaine[i], chaine[i]);
  printf("chaine[%d] = %c (code ASCII : %d)\n", i, chaine[i], chaine[i]);
  return 0;
}

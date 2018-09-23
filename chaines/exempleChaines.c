#include<stdio.h>

#define N 10
#define CLEAR_BUFFER while(getchar() != '\n')

int main()
{
  char chaine[N];
  int i;
  printf("Saisissez une phrase :\n");
  fgets(chaine, N, stdin);
  i = 0;
  while(chaine[i] != 0)
    i++;
  if (i > 0 && chaine[i-1] != '\n')
    CLEAR_BUFFER;
  else
    chaine[i-1] = 0;
  printf("Vous avez saisi :\n%s\n", chaine);
  if (chaine[0] >= 'A' && chaine[0] <= 'Z')
    printf("Cette phrase commence par une majuscule.\n");
  else
    printf("Cette phrase ne commence pas par une majuscule.\n");
  i = 0;
  while(chaine[i] != 0 && chaine[i] != '.')
    i++;
  if (chaine[i] == '.')
    if (chaine[i+1] == 0)
      printf("Cette phrase se termine par un point.\n");
    else
      printf("Vous avez saisi plus d'une phrase.\n"); 
  else
    printf("Cette phrase ne se termine pas par un point.\n"); 
  return 0;
}

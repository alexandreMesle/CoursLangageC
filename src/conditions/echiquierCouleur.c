#include<stdio.h>

int main()
{
  unsigned short i, j;
  printf("Saisissez les coordonnees de la case :\n");
  printf("i = ");
  scanf("%hu", &i);
  printf("j = ");
  scanf("%hu", &j);
  printf("La case (%hu, %hu) est ", i, j);
  if ((i + j) % 2 == 0)
    printf("noire");
  else
    printf("blanche");
  printf(".\n");    
  return 0;
}

#include<stdio.h>

int main()
{
  float inf, sup;
  printf("Saisir un intervalle ([xx, xx]) [");
  scanf("%f, %f]", &inf, &sup);
  printf("Cet intervalle est ");
  if (inf > sup)
    printf("mal");  
  else
    printf("bien");  
  printf(" forme.\n");
  return 0;
}

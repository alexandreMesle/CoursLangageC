#include<stdio.h>

int main()
{
  float inf, sup, valeur;
  printf("Saisir un intervalle ([xx, xx]) [");
  scanf("%f, %f]", &inf, &sup);
  
  if (inf > sup)
    {
      printf("Cet intervalle est mal forme.\n"); 
      return -1;
    }
  printf("Saisir une valeur : ");
  scanf("%f", &valeur);
  printf("%f ", valeur);
  if (inf <= valeur && valeur <= sup)
    printf("appartient");
  else
    printf("n'appartient pas");
  printf(" a l'intervalle [%f, %f].\n", inf, sup);
  return 0;
}

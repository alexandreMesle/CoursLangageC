#include<stdio.h>

int main()
{
 int i, j;
 printf("Saisissez deux valeurs : ");
 scanf("%d %d", &i, &j);
 printf("Le produit de ces deux valeurs est ");
 if ((i < 0 && j < 0) || (i >= 0 &&  j>= 0))
  printf("positif\n.");
 else
  printf("negatif");
 printf(".\n");
 return 0;
}

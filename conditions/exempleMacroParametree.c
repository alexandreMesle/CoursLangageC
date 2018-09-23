#include<stdio.h>

#define RC printf("\n")
#define DECLARER_INT(i) int i
#define AFFICHER_INT(i) printf("%d", i)
#define SAISIR_INT(i) scanf("%d", &i)

int main()
{
  DECLARER_INT(k);
  printf("Saisissez un entier : ");
  SAISIR_INT(k);
  printf("Vous avez saisi ");  
  AFFICHER_INT(k);
  RC;
  return 0;
}

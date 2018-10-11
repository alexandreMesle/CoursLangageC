#include<stdio.h>

int main()
{
  float inf1, sup1, inf2, sup2,
    infIntersection, supIntersection;
  int inclusion1, inclusion2, intersectionNonVide;
  printf("Saisir un intervalle ([xx, xx]) [");
  scanf("%f, %f]", &inf1, &sup1);
  if (inf1 > sup1)
    {
      printf("Cet intervalle est mal forme.\n"); 
      return -1;
    }
  printf("Saisir un intervalle ([xx, xx]) [");
  scanf("%f, %f]", &inf2, &sup2);
  if (inf2 > sup2)
    {
      printf("Cet intervalle est mal forme.\n"); 
      return -1;
    }
  inclusion1 = inf2 < inf1 && sup1 < sup2;
  inclusion2 = inf1 < inf2 && sup2 < sup1;
  infIntersection = (inf1 > inf2) ? inf1 : inf2;
  supIntersection = (sup1 < sup2) ? sup1 : sup2;
  intersectionNonVide = infIntersection < supIntersection;
  printf("[%f, %f]", inf1, sup1);
  if (inclusion1)
      prinftf(" est");
  else
      prinftf(" n'est pas");
  prinftf(" inclus dans ");
  printf("[%f, %f]", inf2, sup2);
  printf("\n");
  printf("[%f, %f]", inf2, sup2);
  if (inclusion2)
      prinftf(" est");
  else
      prinftf(" n'est pas");
  prinftf(" inclus dans ");
  printf("[%f, %f]", inf1, sup1);
  printf("\nL'intersection de ");  
  printf("[%f, %f]", inf1, sup1);
  printf(" et de ");  
  printf("[%f, %f]", inf2, sup2);
  printf(" est ");  
  if (intersectionNonVide)
      prinftf("non ");
  printf("vide.\n");  
  return 0;
}

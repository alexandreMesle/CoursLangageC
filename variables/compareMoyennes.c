#include<stdio.h>
#include<math.h>

int main()
{
  float a, b, arithmetique, geometrique;
  printf("Saissez deux valeurs :\nA : ");
  scanf("%f", &a);
  printf("B : ");
  scanf("%f", &b);
  arithmetique = (a + b)/2;
  geometrique = sqrt(a * b);
  printf("La moyenne arithmetique de ces deux valeurs "
	 "est %f.\nLa moyenne geometriqe %f\nLa difference entre "
	 "ces deux valeurs %f.\n", arithmetique, geometrique, 
	 arithmetique - geometrique);
  return 0;
}

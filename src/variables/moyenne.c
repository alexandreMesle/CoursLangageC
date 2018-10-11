#include<stdio.h>

int main()
{
  float a, b, c, moyenne;
  printf("Saississez 3 valeurs :\n1 : ");
  scanf("%f", &a);
  printf("2 : ");
  scanf("%f", &b);
  printf("3 : ");
  scanf("%f", &c);
  moyenne = (a + b + c)/3.;
  printf("La moyenne de ces trois valeurs est %f.\n", moyenne);
  return 0;
}

#include<stdio.h>

#define EPS 1e-10

int main()
{
  double x, inf, sup, mid;
  do
    {
      printf("Saisissez une valeur positive ou nulle : ");
      scanf("%lf", &x);
    }
  while(x < 0);
  inf = 0;
  sup = x;
  while(sup - inf > EPS)
    {
      mid = (inf + sup)/2;
      if (mid*mid > x)
	sup = mid;
      else
	inf = mid;
    }
  printf("La racine carre de %.10lf est %.10lf (erreur +-%.10lf).\n", 
	 x, (inf + sup)/2, EPS);
  return 0;
}

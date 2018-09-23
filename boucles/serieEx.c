#include<stdio.h>
#include<stdlib.h>

#define EPS 1e-10

#define ABS(i) ((i > 0.) ? i : -i)

int main()
{
  double terme = 1., serie = 0., facteur = 1., x;
  printf("x = ");
  scanf("%lf", &x);
  while(ABS(terme) > EPS)
    {
      serie += terme;
      terme *= (x/facteur);
      facteur += 1.;
    }
  printf("e = %.12lf a %.12lf pres.\n", serie, EPS);
  return 0;
}

#include<stdio.h>
#include<stdlib.h>

#define EPS 1e-20

#define ABS(i) ((i > 0.) ? i : -i)

int main()
{
  double terme = 1, serie = 0;
  while(ABS(terme) > EPS)
    {
      serie += terme;
      terme *= 0.5;
    }
  printf("2 = %.12lf a %.12lf pres.\n", serie, EPS);
  return 0;
}

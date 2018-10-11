#include<stdio.h>

int main()
{
  double a, b, x;
  printf("Saisissez les coefficients de l'equation (E) : ax + b = 0\na = ");
  scanf("%lf", &a);
  printf("b = ");
  scanf("%lf", &b);
  if(a != 0)
    {
      x = -b/a;
      printf("La solution de (E) est x = %lf", x);
    }
  else
    {
      if(b == 0)
	printf("Tout reel est solution de (E)");
      else
	printf("(E) n'a pas de solution");
    }
  printf(".\n");
  return 0;
}

#include<stdio.h>
#include<math.h>

int main()
{
  double a, b, c, x1, x2, delta;
  printf("Saisissez les coefficients de l'equation (E) : "
	 "ax^2 + bx + c = 0\na = ");
  scanf("%lf", &a);
  printf("b = ");
  scanf("%lf", &b);
  printf("c = ");
  scanf("%lf", &c);
  if (a != 0)
    {
      delta = b*b - 4*a*c;
      if(delta > 0)
	{
	  x1 = (sqrt(delta) - b)/(2 * a);
	  x2 = (- sqrt(delta) - b)/(2 * a);
	  printf("Les solutions de (E) sont %lf et %f", x1, x2);
	}
      else
	{
	  if (delta == 0)
	    {
	      x1 = (- b)/(2 * a);
	      printf("La solution de (E) est x = %lf", x1);
	    }
	  else
	    printf("(E) n'a pas de solution reelle");
	}
    }
  else
    {
      if(b != 0)
	{
	  x1 = -c/b;
	  printf("La solution de (E) est x = %lf", x1);
	}
      else
	{
	  if(c == 0)
	    printf("Tout reel est solution de (E)");
	  else
	    printf("(E) n'a pas de solution");
	}
    }
  printf(".\n");
  return 0;
}

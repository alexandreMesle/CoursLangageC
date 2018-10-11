#include<stdio.h>

int main()
{
  double d; 
  printf("Saisissez une valeur entre 0 et 1: ");
  scanf("%lf", &d);
  printf("Sa représentation binaire est [0.");
  while(d != 0)
    {
      d *=2 ;
      printf("%d", (int)(d));
      d -= (d>=1);
    }
  printf("]\n");
  return 0;
}

#include<stdio.h>

int main()
{
  float a;
  printf("Saisissez une valeur\n");
  scanf("%f", &a);
  printf("La valeur absolue de %f est ", a);
  if(a < 0)
    a = -a;
  printf("%f.\n", a);
  return 0;
}

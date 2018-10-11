#include<stdio.h>

int main()
{
  int a, b, c, min;
  printf("Saisissez trois valeurs : \na = ");
  scanf("%d", &a);
  printf("b = ");
  scanf("%d", &b);
  printf("c = ");
  scanf("%d", &c);
  min = a;
  if(b < min)
    min = b;
  if(c < min)
    min = c;
  printf("La plus petite de ces valeurs est %d.", min);
  printf("\n");
   return 0;
}

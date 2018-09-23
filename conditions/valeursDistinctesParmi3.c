#include<stdio.h>

int main()
{
  int a, b, c, nbd;
  printf("Saisissez trois valeurs : \na = ");
  scanf("%d", &a);
  printf("b = ");
  scanf("%d", &b);
  printf("c = ");
  scanf("%d", &c);
  if (a == b && a == c)
    nbd = 1;
  else
    if(a == b || a == c || b == c)
      nbd = 2;
    else
      nbd = 3;
  printf("Il y a %d valeur(s) distincte(s).\n", nbd);
  return 0;
}

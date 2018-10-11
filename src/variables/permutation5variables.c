#include<stdio.h>

int main()
{
  int a, b, c, d, e, temp;
  printf("Saississez les valeurs de 5 variables :\nA = ");
  scanf("%d", &a);
  printf("B = ");
  scanf("%d", &b);
  printf("C = ");
  scanf("%d", &c);
  printf("D = ");
  scanf("%d", &d);
  printf("E = ");
  scanf("%d", &e);
  temp = d;
  d = a;
  a = temp;
  temp = b;
  b = c;
  c = e;
  e = temp;
  printf("Apres permutation, les valeurs des variables sont : "
	 "\nA = %d\nB = %d\nC = %d\nD = %d\nE = %d\n", 
	 a, b, c, d, e);
  return 0;
}

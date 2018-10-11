#include<stdio.h>

int main()
{
  int a, b, c, d, temp;
  printf("Saississez les valeurs de 4 variables :\nA = ");
  scanf("%d", &a);
  printf("B = ");
  scanf("%d", &b);
  printf("C = ");
  scanf("%d", &c);
  printf("D = ");
  scanf("%d", &d);
  temp = a;
  a = c;
  c = temp;
  temp = b;
  b = d;
  d = temp;
  printf("Apres permutation, les valeurs des variables sont : "
	 "\nA = %d\nB = %d\nC = %d\nD = %d\n", a, b, c, d);
  return 0;
}

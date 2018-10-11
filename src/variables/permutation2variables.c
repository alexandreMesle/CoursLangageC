#include<stdio.h>

int main()
{
  int a, b, temp;
  printf("Saississez les valeurs de 2 variables :\nA = ");
  scanf("%d", &a);
  printf("B = ");
  scanf("%d", &b);
  temp = a;
  a = b;
  b = temp;
  printf("Apres permutation, les valeurs des variables sont : "
	 "\nA = %d\nB = %d\n", a, b);
  return 0;
}

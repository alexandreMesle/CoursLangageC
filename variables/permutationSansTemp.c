#include<stdio.h>

int main()
{
  int a, b;
  printf("Saississez les valeurs de 2 variables :\nA = ");
  scanf("%d", &a); // notons x cette valeur, a = x
  printf("B = ");
  scanf("%d", &b); // notons y cette valeur, b = y
  a ^= b; // a = x^y, b = y
  b ^= a; // a = x^y, b = y^a = y^x^y = x
  a ^= b; // a = x^y^x = y, b = y
  printf("Apres permutation, les valeurs des variables sont : "
	 "\nA = %d\nB = %d\n", a, b);
  return 0;
}

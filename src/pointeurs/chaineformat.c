#include<stdio.h>

int main()
{
  int x = 3;
  int* p;
  p = &x;
  printf("p contient la valeur %X, qui n'est autre que l'adresse %X de x\n", 
	 p, &x);
  return 0;
}

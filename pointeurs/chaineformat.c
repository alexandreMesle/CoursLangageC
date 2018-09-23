#include<stdio.h>

void main()
{
  int x = 3;
  int* p;
  p = &x;
  printf("p contient la valeur %X, qui n'est autre que l'adresse %X de x", 
	 p, &x); 
}

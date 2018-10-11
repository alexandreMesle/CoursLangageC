#include<stdio.h>

int main()
{
  unsigned short s, sSansDernierBit, dernierBit;
  printf("Saisissez une valeur : ");
  scanf("%hu", &s);
  sSansDernierBit = (s & 254);
  dernierBit = (s & 1);
  dernierBit = ~dernierBit & 1;
  s = sSansDernierBit | dernierBit;
  printf("Apres modification du dernier bit, cette valeur est " 
	 "%hu\n", s);
  return 0;
}

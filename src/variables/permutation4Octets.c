#include<stdio.h>

int main()
{
  unsigned long l;
  unsigned short octet1, octet2, octet3, octet4;
  printf("Saisissez une valeur : ");
  scanf("%lu", &l);
  octet4 = 255 & l;
  l >>= 8;
  octet3 = 255 & l;
  l >>= 8;
  octet2 = 255 & l;
  l >>= 8;
  octet1 = 255 & l;
  l = octet4;
  l <<= 8;
  l |= octet3;
  l <<= 8;
  l |= octet2;
  l <<= 8;
  l |= octet1;  
  printf("Apres permutation circulaire des octets, cette valeur est " 
	 "%lu\n", l);
  return 0;
}

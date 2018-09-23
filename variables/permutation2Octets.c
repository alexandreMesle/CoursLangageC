#include<stdio.h>

int main()
{
  unsigned int u, temp;
  printf("Saisissez une valeur : ");
  scanf("%u", &u);
  temp = u & 255;
  temp <<= 8;
  u >>= 8;
  u |= temp;
  printf("Apres permutation circulaire des octets, cette valeur est " 
	 "%u\n", u);
  return 0;
}

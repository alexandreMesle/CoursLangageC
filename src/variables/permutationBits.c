#include<stdio.h>

int main()
{
  unsigned short s, firstBit;
  printf("Saisissez une valeur : ");
  scanf("%hu", &s);
  firstBit = s & 1;
  s >>= 1;
  firstBit <<=7;
  s |= firstBit;
  printf("Apres permutation circulaire des bits, cette valeur est "
	 "%hu\n", s);
  return 0;
}

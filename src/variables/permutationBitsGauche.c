#include<stdio.h>

int main()
{
  unsigned char s, firstBit;
  printf("Saisissez une valeur : ");
  scanf("%hd", &s);
  firstBit = s & 128;
  s <<= 1;
  firstBit >>=7;
  s |= firstBit;
  printf("Apres permutation circulaire des bits, cette valeur est "
	 "%d\n", s);
  return 0;
}

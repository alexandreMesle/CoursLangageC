#include<stdio.h>

int main()
{
  short s, k;
  unsigned short nbBits = sizeof(unsigned short)*8,
   firstMask = 1<<(nbBits-1), lastMask =1,
    firstBit, lastBit,
    result = 0;
  printf("Saisissez une valeur : ");
  scanf("%hu", &s);
  for (k = nbBits - 1 ; k >= 1 ; k-=2)
    {
      firstBit = firstMask & s;
      lastBit = lastMask & s;
      firstBit >>= k;
      lastBit <<= k;
      result |= firstBit | lastBit;
      firstMask>>=1;
      lastMask<<=1;
    }
  printf("Après inversion de l'ordre des bits, la valeur que vous avez "
         "saisi est %hu.\n", result);
  return 0;
}

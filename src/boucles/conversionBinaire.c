#include<stdio.h>

int main()
{
  unsigned short s, i, mask = 1, nbBits = sizeof(unsigned short)*8; 
  printf("Saisissez une valeur : ");
  scanf("%hu", &s);
  printf("Sa représentation binaire est [");
  mask <<= nbBits - 1;
  for(i = nbBits ; i >= 1 ; i--)
    {
      if ((i - nbBits) && !(i%8)) printf(".");
      printf("%hu", (s&mask)!=0);
      mask>>=1;
    }
  printf("]\n");
  return 0;
}

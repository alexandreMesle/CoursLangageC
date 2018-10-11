#include<stdio.h>

int main()
{
  unsigned int i;
  printf("Saisissez un nombre positif : ");
  scanf("%u", &i);
  while(i > 0)
    {
      printf("%u\n", i);
      i--;
    }
  printf("0\n");
  return 0;
}

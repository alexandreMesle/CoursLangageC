#include<stdio.h>

int main()
{
  unsigned int i;
  printf("Saisissez un nombre positif : ");
  scanf("%u", &i);
  for(; i > 0 ; i--)
    printf("%u\n", i);
  printf("0\n");
  return 0;
}

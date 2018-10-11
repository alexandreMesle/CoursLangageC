#include<stdio.h>

int main()
{
  unsigned int i;
  printf("Saisissez un nombre positif : ");
  scanf("%u", &i);
  do
    {
      printf("%u\n", i);
      i--;
    }
  while(i != 0);
  printf("0\n");
  return 0;
}

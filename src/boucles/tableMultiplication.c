#include<stdio.h>

int main()
{
  unsigned short s, i;
  printf("Saisissez une valeur positive : ");
  scanf("%hu", &s);
  for(i = 1 ; i <= 10 ; i++)
    printf("%2.hu * %2.hu = %2.hu\n", i, s, s*i);
  return 0;
}

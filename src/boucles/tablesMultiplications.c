#include<stdio.h>

int main()
{
  unsigned short i, j;
  for(i = 1 ; i <= 10 ; i++)
    {
      for(j = 1 ; j <= 10 ; j++)
	printf("%3.hu ", i*j);
      printf("\n");
    }
  return 0;
}

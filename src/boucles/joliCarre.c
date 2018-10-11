#include<stdio.h>

int main()
{
  unsigned int i, j, n;
  
  printf("n = ");
  scanf("%u", &n);
  for(i = 1 ; i <= n; i++)
    {
      for(j = 1 ; j <= n; j++)
	printf("X  ");
      printf("\n");
      if (i != n)
	printf("\n");
    }
  return 0;
}

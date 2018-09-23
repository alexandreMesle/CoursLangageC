#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int main()
{
  int** T;
  int i, j, n;
  printf("Valeur de n ? ");
  scanf("%d", &n);
  T = (int**)malloc(n * sizeof(int*));
  if (T == NULL)
    exit(0);
  for(i = 0 ; i < n ; i++)
    {
      *(T + i) = (int*)malloc(n * sizeof(int));
      if (*(T + i) == NULL)
	exit(0);
      for(j = 0 ; j < n ; j++)
	*(*(T + i) + j) = 0;
      *(*(T + i) + i) = 1;
    }  
  for(i = 0 ; i < n ; i++)
    {
      for(j = 0 ; j < n ; j++)
	printf("%d ", *(*(T + i) + j));
      printf("\n");
    }
  for(i = 0 ; i < n ; i++)
    free(*(T + i));
  free(T);
  return 0;
}


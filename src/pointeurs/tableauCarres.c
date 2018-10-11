#include<stdio.h>
#include<stdlib.h>

int main()
{
  int* t;
  int k, n;
  printf("Quelle est la taille du tableau ? ");
  scanf("%d", &n);
  t = (int*)malloc(n * sizeof(int));
  if (t == NULL)
    exit(0);
  *t = 1;
  for(k = 1 ; k < n ; k++)
      *(t + k) = *(t + k - 1) + 2;
  printf("%d premiers nombres impairs : \n", n);
  for(k = 0 ; k < n ; k++)
    printf("%d ", *(t + k));
  printf("\n");
  for(k = 1 ; k < n ; k++)
    *(t + k) += *(t + k - 1);
  printf("%d premiers carres : \n", n);
  for(k = 0 ; k < n ; k++)
    printf("%d ", *(t + k));
  printf("\n");  
  free(t);
  return 0;
}


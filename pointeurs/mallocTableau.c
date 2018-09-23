#include<stdio.h>
#include<malloc.h>
#define N 26

void initTab(int* k, int n)
{
  int i;
  for(i = 0 ; i < n ; i++)
     *(k + i) = i + 1;
}

void afficheTab(int* k, int n)
{
  int i;
  for(i = 0 ; i < n ; i++)
    printf("%d ", *(k + i));
  printf("\n");
}

int main()
{
  int* p;
  p = (int*)malloc(N*sizeof(int));
  if (p == NULL)
    return -1;
  initTab(p, N);
  afficheTab(p, N);
  free(p);
  return 0;
}

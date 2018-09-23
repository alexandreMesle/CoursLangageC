#include<stdio.h>
#define N 30

void initTab(int* k, int n)
{
  int i;
  *k = 1;
  for(i = 1 ; i < n ; i++)
     *(k + i) = *(k + i - 1) + 1;
}

void afficheTab(int* k, int n)
{
  int i;
  for(i = 0 ; i < n ; i++)
    printf("%d ", *(k + i));
  printf("\n");
}

main()
{
  int t[N];
  initTab(t, N);
  afficheTab(t, N);
}

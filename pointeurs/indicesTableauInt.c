#include<stdio.h>
#define N 30

void initTab(int* k, int n)
{
  int i;
  *k = 1;
  for(i = 1, k++ ; i < n ; i++, k++)
     *k = *(k - 1) + 1;
}

void afficheTab(int* k, int n)
{
  int i;
  for(i = 0 ; i < n ; i++, k++)
    printf("%d ", *k);
  printf("\n");
}

int main()
{
  int t[N];
  initTab(t, N);
  afficheTab(t, N);
  return 0;
}

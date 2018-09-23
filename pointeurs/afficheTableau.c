#include<stdio.h>

void initTab(int K[], int n)
{
  int i;
  for(i = 0 ; i < n ; i++)
    K[i] = i + 1;
}

void afficheTab(int K[], int n)
{
  int i;
  for(i = 0 ; i < n ; i++)
    printf("%d\n", K[i]);
}

int main()
{
  int T[50];
  initTab(T, 50);
  afficheTab(T, 50);
  return 0;
}

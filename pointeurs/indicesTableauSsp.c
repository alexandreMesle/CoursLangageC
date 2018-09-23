#include<stdio.h>
#define N 26

void initTab(char* k, int n)
{
  int i;
  int v = 'A';
  for(i = 0 ; i < n ; i++)
     *(k + i) = v++;
}

void afficheTab(char* k, int n)
{
  int i;
  for(i = 0 ; i < n ; i++)
    printf("%c ", *(k + i));
  printf("\n");
}

main()
{
  char t[N];
  initTab(t, N);
  afficheTab(t, N);
}

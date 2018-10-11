#include<stdio.h>
#include<stdlib.h>
#define N 26

char* initTab(int n)
{
  char* k;
  int i;
  char value = 'a';
  k = (char*)malloc(n*sizeof(char));
  if (k == NULL)
    return NULL;
  for(i = 0 ; i < n ; i++, value++)
     *(k + i) = value;
  return k;
}

void afficheTab(char* k, int n)
{
  int i;
  for(i = 0 ; i < n ; i++, k++)
    printf("%c ", *k);
  printf("\n");
}

int main()
{
  char* p = initTab(N);
  if (p == NULL)
    return -1;
  afficheTab(p, N);
  free(p);
  return 0;
}

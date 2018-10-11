#include<stdio.h>

#define N 10

int main()
{
  int T[N];
  int i;
  for(i = 0 ; i < N ; i++)
    T[i] = i + 1;
  for(i = 0 ; i < N ; i++)
    printf("T[%d] = %d\n", i, T[i]);
  return 0;
}


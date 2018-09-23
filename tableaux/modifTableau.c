#include<stdio.h>

#define N 20

int main()
{
  int T[N], i;
  for(i = 0 ; i < N ; i++)
    T[i] = i *i % 17;
  for(i = 0 ; i < N ; i++)
    printf("T[%d] = %d\n", i, T[i]);
  return 0;
}

#include<stdio.h>

#define N 10

int main()
{
  int T[N], Q[N];
  int i;
  for(i = 0 ; i < N ; i++)
    T[i] = i + 1;
  Q[0] = T[N - 1];
  for (i = 1 ; i < N ; i++)
    Q[i] = T[i - 1];
  for(i = 0 ; i < N ; i++)
    printf("Q[%d] = %d\n", i, Q[i]);
  return 0;
}

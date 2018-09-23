#include<stdio.h>

#define N 10

int main()
{
  int T[N];
  int i, temp;
  for(i = 0 ; i < N ; i++)
    T[i] = i + 1;
  temp =  T[9];
  for(i = N - 1 ; i >= 1 ; i--)
     T[i] = T[i - 1];
  T[0] = temp;
  for(i = 0 ; i < N ; i++)
    printf("T[%d] = %d\n", i, T[i]);
  return 0;
}

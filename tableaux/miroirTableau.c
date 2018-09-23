#include<stdio.h>

#define N 10

int main()
{
  int T[N];
  int i, j, temp;
  for(i = 0 ; i < N ; i++)
    T[i] = i + 1;
  i = 0 ; 
  j = N - 1;
  while(i < j)
    {
      temp = T[i] ;
      T[i] = T[j] ;
      T[j] = temp;
      i++; 
      j--;
      }
  for(i = 0 ; i < N ; i++)
    printf("T[%d] = %d\n", i, T[i]);
  return 0;
}

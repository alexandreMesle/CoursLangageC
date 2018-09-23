#include<stdio.h>

#define N 10

int main()
{
  int T[N];
  int i, somme = 0;
  for(i = 0 ; i < N ; i++)
    T[i] = i;
  for(i = 0 ; i < N ; i++)
    somme += T[i];
  printf("La somme des elements du tableau est %d\n", somme);
  return 0;
}


#include<stdio.h>

#define N 10

int main()
{
  int T[N];
  int i, t;
  for(i = 0 ; i < N ; i++)
    T[i] = i;
  printf("Saisissez une valeur : ");
  scanf("%d", &t);
  i = 0;
  while(i < N && T[i] != t)
    i++;
  if (i == N)
    printf("%d ne se trouve pas dans le tableau.\n", t);
  else
    printf("%d se trouve dans le tableau a l'indice %d.\n", t, i);
    return 0;
}

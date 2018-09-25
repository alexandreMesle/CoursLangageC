#include<stdio.h>

#define N 10

int main()
{
  int E[N], i, t;
  printf("Saisissez dix valeurs : \n");
  for (i = 0 ; i < N ; i++)
    {
      printf("%d : ", i+1);
      scanf("%d", &E[i]);
    }
  printf("Saissez une valeur \n");
  scanf("%d", &t);
  i = 0;
  while (i < N && E[i] != t)
    {printf("%d %d\n", i, E[i]);i++;}
    if (i == N)
      printf("%d ne fait pas partie des dix valeurs saisies", t);
    else
      printf("%d est la %d-eme valeur saisie", t, i+1);
  printf("\n");
  return 0;
}

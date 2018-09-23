#include<stdio.h>

#define N 10

#define SAISIR_INT(num, nom) \
{ \
  printf("%d : ", num); \
  scanf("%d", &(nom)); \
}

int main()
{
  int E[N], i, t;
  printf("Saisissez dix valeurs : \n");
  for (i = 0 ; i < N ; i++)
    SAISIR_INT(i+1, E[i]);
  printf("Saissez une valeur \n");
  scanf("%d", &t);
  i = 0;
  while (i < N && E[i] != t)
    i++;
  if (i == N)
    printf("%d ne fait pas partie des dix valeurs saisies", t);
  else
    printf("%d est la %d-eme valeur saisie", t, i+1);
  printf("\n");
  return 0;
}

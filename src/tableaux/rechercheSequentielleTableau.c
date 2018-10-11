#include<stdio.h>

#define N 20

int main()
{
  int T[N], i, t;
  for(i = 0 ; i < N ; i++)
    T[i] = i *i % 17;
  printf("Saisissez une valeur : ");
  scanf("%d", &t);
  printf("Voici la liste des indices des occurrences de "
	 "%d dans le tableau :\n", t);
  for (i = 0 ; i < N ; i++)
    if (T[i] == t)
      printf("%d\n", i);
  return 0;
}

#include<stdio.h>

#define N 20

int main()
{
  int T[N], I[N], i, t, nbV = 0;
  for(i = 0 ; i < N ; i++)
    T[i] = i *i % 17;
  printf("Saisissez une valeur : ");
  scanf("%d", &t);
  for (i = 0 ; i < N ; i++)
    if (T[i] == t)
      I[nbV++] = i;
  if (nbV == 0)
    printf("%d n'est pas dans le tableau.\n", t);
  else
    {
      printf("%d apparait dans le tableau aux indices suivants :\n", t);
      for(i = 0 ; i < nbV ; i++)
	printf("%d\n", I[i]);
    }
  return 0;
}

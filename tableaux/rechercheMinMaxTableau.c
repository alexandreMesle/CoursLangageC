#include<stdio.h>

#define N 20

int main()
{
  int T[N], i, min, max;
  for(i = 0 ; i < N ; i++)
    T[i] = i * i % 17;
  min = max = T[0];
  for (i = 1 ; i < N ; i++)
    {
      if (T[i] > max)
	max = T[i];
      if (T[i] < min)
	min = T[i];      
    }
  printf("Le plus petit element est %d, le plus grand est %d.\n", min, max);
    return 0;
}

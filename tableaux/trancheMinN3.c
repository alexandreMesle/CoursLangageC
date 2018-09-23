#include<stdio.h>
#include<stdlib.h>
#define N 20

int main()
{
  int T[N], i, j, k;
  int valeurTrancheMin, debutTrancheMin, finTrancheMin, valeurTranche ;
  for (i = 0 ; i < N ; i++)
    {
      T[i] = random()%27 - 11;
      printf("T[%d] = %d\n", i, T[i]);
    }
  valeurTrancheMin = T[0]; 
  debutTrancheMin = 0;
  finTrancheMin = 0;
  for (i = 0  ; i < N ; i++)
    for (j = i ; j < N ; j++)
      {
	valeurTranche = 0;
	for (k = i ; k <= j ; k++)
	  valeurTranche += T[k];
	if(valeurTranche < valeurTrancheMin)
	  {
	    valeurTrancheMin = valeurTranche;
	    debutTrancheMin = i;
	    finTrancheMin = j;	    
	  }
      }
  printf("La tranche minimale est situee entre les indices %d et %d\n", 
	 debutTrancheMin, finTrancheMin);
  return 0;
}

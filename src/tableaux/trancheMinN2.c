#include<stdio.h>
#include<stdlib.h>
#define N 20

int main()
{
  int T[N], i, j;
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
    {
      valeurTranche = 0;
      for (j = i ; j < N ; j++)
	{
	  valeurTranche += T[j];
	  if(valeurTranche < valeurTrancheMin)
	    {
	      valeurTrancheMin = valeurTranche;
	      debutTrancheMin = i;
	      finTrancheMin = j;	    
	    }
	}
    }
  printf("La tranche minimale est situee entre les indices %d et %d\n", 
	 debutTrancheMin, finTrancheMin);
  return 0;
}

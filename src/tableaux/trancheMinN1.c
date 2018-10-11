#include<stdio.h>
#include<stdlib.h>
#define N 20

int main()
{
  int T[N], i;
  int valeurTrancheMin, debutTrancheMin, finTrancheMin;
  int valeurTrancheMinAvecI, debutTrancheMinAvecI, finTrancheMinAvecI;
  for (i = 0 ; i < N ; i++)
    {
      T[i] = random()%27 - 11;
      printf("T[%d] = %d\n", i, T[i]);
    }
  valeurTrancheMin = T[0]; 
  debutTrancheMin = 0;
  finTrancheMin = 0;
  valeurTrancheMinAvecI = T[0]; 
  debutTrancheMinAvecI = 0;
  finTrancheMinAvecI = 0;
  for (i = 1  ; i < N ; i++)
    {
      if (valeurTrancheMinAvecI > 0)
	{
	  valeurTrancheMinAvecI = T[i]; 
	  debutTrancheMinAvecI = i;
	  finTrancheMinAvecI = i;	  
	}
      else
	{
	  valeurTrancheMinAvecI += T[i]; 
	  finTrancheMinAvecI = i;	  
	}
      if(valeurTrancheMinAvecI < valeurTrancheMin)
	{
	  valeurTrancheMin = valeurTrancheMinAvecI; 
	  debutTrancheMin = debutTrancheMinAvecI;
	  finTrancheMin = finTrancheMinAvecI;	  
	}
    }
  printf("La tranche minimale est situee entre les indices %d et %d\n", 
	 debutTrancheMin, finTrancheMin);
  return 0;
}

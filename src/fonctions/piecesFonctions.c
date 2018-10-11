#include<stdio.h>

#define EPS 0.001

float calculQte(float somme, float valeurPiece, unsigned int* nbPieces)
{
  *nbPieces = (somme + EPS)/valeurPiece;
  return somme - (float)*nbPieces * valeurPiece;
  
}

void setQte(float somme, float* pieces, unsigned int* qtes, unsigned int n)
{
  unsigned int i;
  for (i = 0 ; i < n ; i++)
    {
      somme = calculQte(somme, *(pieces + i), qtes + i);
    }
}

void printIntTab(unsigned int* t, unsigned int n)
{
  if (n > 0)
    {
      printf("%u ", *t);
      printIntTab(t + 1, n - 1);
    }
  else
    {
      printf("\n");
    }
}

int main()
{
  float pieces[6] = {0.5, 0.2, 0.1, 0.05, 0.02, 0.01};
  unsigned int qtes[6];
  setQte(1.41, pieces, qtes, 6);
  printIntTab(qtes, 6);
  return 0;
}

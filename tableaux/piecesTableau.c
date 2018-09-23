#include<stdio.h>

#define N 6
#define EPS 0.001

int main()
{
  float pieces[N] = {0.5, 0.2, 0.1, 0.05, 0.02, 0.01}, somme, reste;
  int i, nbPieces[N];
  do
    {   
      printf("Saisissez une somme strictement positive : ");
      scanf("%f", &somme);
    }
  while(somme <= 0);
  reste = somme ;
  for (i = 0 ; i < N ; i++)
    {
      nbPieces[i] = (reste+EPS) / pieces[i];
      reste -= nbPieces[i]*pieces[i];
    }
  printf("Pour payer cette somme avec des pieces, il vous faudra : ");
  for (i = 0 ; i < N ; i++)
    if (nbPieces[i] != 0)
      printf("%d piece%s de %.2f euros\n", 
	     nbPieces[i], ((nbPieces[i] > 1) ? "s" : ""), pieces[i]);
  return 0;
}

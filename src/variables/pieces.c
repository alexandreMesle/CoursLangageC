#include<stdio.h>

#define EPS 0.001

int main()
{
  float valeur;
  int nbPieces;
  printf("Saissez la somme : ");
  scanf("%f", &valeur);
  printf("Pour la payer, vous aurez besoin de :\n");
  /*--------*/
  nbPieces = (valeur + EPS)/ 0.5;
  printf("%d piece(s) de 0.5 euros\n", nbPieces);
  valeur -= nbPieces * 0.5;
  /*--------*/
  nbPieces = (valeur + EPS)/ 0.2;
  printf("%d piece(s) de 0.2 euros\n", nbPieces);
  valeur -= nbPieces * 0.2;
  /*--------*/
  nbPieces = (valeur + EPS)/ 0.1;
  printf("%d piece(s) de 0.1 euros\n", nbPieces);
  valeur -= nbPieces * 0.1;
  /*--------*/
  nbPieces = (valeur + EPS)/ 0.05;
  printf("%d piece(s) de 0.05 euros\n", nbPieces);
  valeur -= nbPieces * 0.05;
  /*--------*/
  nbPieces = (valeur + EPS)/ 0.02;
  printf("%d piece(s) de 0.02 euros\n", nbPieces);
  valeur -= nbPieces * 0.02;
  /*--------*/
  nbPieces = (valeur + EPS)/ 0.01;
  printf("%d piece(s) de 0.01 euros\n", nbPieces);
  valeur -= nbPieces * 0.01;
  return 0;
}

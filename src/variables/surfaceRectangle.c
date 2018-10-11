#include<stdio.h>

int main()
{
  float largeur, longueur, surface;
  printf("largeur : ");
  scanf("%f", &largeur);
  printf("longueur : ");
  scanf("%f", &longueur);
  surface = largeur * longueur;
  printf("La surface de ce rectangle est %f.\n", surface);
  return 0;
}

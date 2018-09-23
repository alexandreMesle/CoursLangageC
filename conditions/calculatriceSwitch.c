#include<stdio.h>
#include<stdlib.h>

int main()
{
  float gauche, droite, resultat;
  int erreur = 0;
  char operateur;
  printf("Operande gauche : ");
  scanf("%f", &gauche);
  getchar();
  printf("Operateur : ");
  scanf("%c", &operateur);
  printf("Operande droit : ");
  scanf("%f", &droite);
  getchar();
  switch(operateur)
    {
    case '+' : resultat = gauche + droite; break;
    case '-' : resultat = gauche - droite; break;
    case '/' : resultat = gauche / droite; break;
    case '*' : resultat = gauche * droite; break;
    default : erreur = 1;
    }
  if (erreur)    
    printf("Saisie erronnee.\n");
  else
    printf("%.2f%c%.2f = %f\n", gauche, operateur, droite, resultat);
  return 0;
}

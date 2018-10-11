#include<stdio.h>
#include<stdlib.h>

int main()
{
  unsigned short iD, jD, iA, jA;
  printf("Saisissez les coordonnees de la case de depart : \n");
  printf("i = ");
  scanf("%hu", &iD);
  printf("j = ");
  scanf("%hu", &jD);
  printf("Saisissez les coordonnees de la case de la case d'arrivee : \n");
  printf("i = ");
  scanf("%hu", &iA);
  printf("j = ");
  scanf("%hu", &jA);
  printf("Le mouvement de cavalier (%hu, %hu) -> (%hu, %hu) est ", 
	 iD, jD, iA, jA); 
  if ((abs(iA - iD) == 1 && abs(jA - jD) == 2) 
      || (abs(iA - iD) == 2 && abs(jA - jD) == 1))
    printf("valide");
  else
    printf("invalide");
  printf(".\n");    
  return 0;
}

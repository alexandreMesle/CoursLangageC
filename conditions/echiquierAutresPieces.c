#include<stdio.h>
#include<stdlib.h>

int main()
{
  unsigned short iD, jD, iA, jA, piece;
  printf("Quelle piece souhaitez-vous deplacer ?n");
  printf("0 = Cavalier\n");
  printf("1 = Tour\n"); 
  printf("2 = Fou\n"); 
  printf("3 = Damen"); 
  printf("4 = Roi\n");
  scanf("%hu", &piece);
  printf("Saisissez les coordonnees de la case de depart : \n");
  printf("i = "); 
  scanf("%hu", &iD); 
  if (iD<1 || iD>8) 
    {
      printf("coordonnee invalide\n"); 
      return 1; 
    }
  printf("j = "); 
  scanf("%hu", &jD); 
  if (jD<1 || jD>8) 
    {
      printf("coordonnee invalide\n"); 
      return 1; 
    }
  printf("Saisissez les coordonnees de la case d'arrivee : \n");
  printf("i = "); 
  scanf("%hu", &iA); 
  if (iA<1 || iA>8) 
    {
      printf("coordonnee invalide\n"); 
      return 1; 
    }
  printf("j = "); 
  scanf("%hu", &jD); 
  if (jD<1 || jD>8) 
    {
      printf("coordonnee invalide\n"); 
      return 1; 
    }
  printf("Le mouvement (%hu, %hu) -> (%hu, %hu) est ", 
	 iD, jD, iA, jA); 
  switch(piece)
    {
    case 0 : 
      if( (abs(iA - iD) == 1 && abs(jA - jD) == 2)
	  || (abs(iA - iD) == 2 && abs(jA - jD) == 1))
	printf("valide"); 
      else
	printf("invalide"); 	    
    case 1 : 
      if( iA == iD || jA == jD )
	printf("valide"); 
      else
	printf("invalide"); 	    
    case 2 :
      if(abs(iA - iD) ==  abs(jA - jD))
	printf("valide"); 
      else
	printf("invalide"); 	    
    case 3 :
      if(iA == iD 
	 || jA == jD
	 || abs(iA - iD) ==  abs(jA - jD))
	printf("valide"); 
      else
	printf("invalide"); 	    
    case 4 : 
      if (abs(iA - iD) <= 1
	  && abs(jA - jD) <= 1)
	printf("valide"); 
      else
	printf("invalide"); 
    default: printf("System Error. It is recommended that " 
		    "you format your hard disk."); 
      return 1;
    }
  printf(".\n");    
  return 0;
}

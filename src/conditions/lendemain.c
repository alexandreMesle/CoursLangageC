#include<stdio.h>

int main()
{
  int jour, mois, annee, nbJours, 
    erreur = 0;
  printf("Saisissez la date : (jj/mm/aaaa) ");
  scanf("%d/%d/%d", &jour, &mois, &annee);
  switch(mois)
    {
    case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12:
      nbJours = 31; break;
    case 4 : case 6 : case 9 : case 11 : 
      nbJours = 30; break;
    case 2 : 
      if (annee % 4 || ! (annee % 100))
	nbJours = 28;
      else
	nbJours = 29;
      break;
    default : 
      erreur = 1;
    }
  if (erreur)
    {
      printf("Saisie erronnee : %2.2d/%2.2d/%4.4d\n",
	 jour, mois, annee);
      return -1;
    }
  printf("Le lendemain du %2.2d/%2.2d/%4.4d est le ", 
	 jour, mois, annee);
  jour++;
  if (jour == nbJours + 1)
    {
      jour = 1;
      mois++;
      if (mois == 13)
	{
	  mois = 1;
	  annee++;
	}
    }
  printf(" est le %2.2d/%2.2d/%4.4d.\n", 
	 jour, mois, annee);   
  return 0;
}

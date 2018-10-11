#include "../../src/methodo/tableau.h"

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

#include "util.h"

/**********************************************************/

void afficheMails(char* mails)
{
  int indice = 0;
  printf("Liste des contacts : \n");
  while(indice < NB_MAILS && *getMail(mails, indice))
    {
      printf("%d : %s\n", indice + 1, getMail(mails, indice));
      indice++;
    }
}

/**********************************************************/

char* getMail(char* mails, int i)
{
  return mails + i * SIZE_MAIL;
}
 
/**********************************************************/

int nombreMails(char* mails)
{
  int indice = 0;
  while(indice < NB_MAILS && *getMail(mails, indice))
      indice++;
  return indice;
}

/*****************************************************/

char* creerMails()
{
  char* adr = (char*)malloc(sizeof(char) * SIZE_MAIL * NB_MAILS);
  int i;
  if (adr == NULL)
    {
      printf("Heap overflow");
      exit(0);
    }
  for(i = 0 ; i < NB_MAILS ; i++)
      *getMail(adr, i) = 0;
  return adr;
}

/*****************************************************/

void detruitMails(char* mails)
{
  free(mails);
}

/**********************************************************/

void supprimeMail(char* mails, int indice)
{
  while(indice < NB_MAILS && *getMail(mails, indice + 1))
    {
      strncpy(getMail(mails, indice), 
	      getMail(mails, indice + 1), 
	      SIZE_MAIL);
      indice++;
    }
  if(indice < NB_MAILS)
    *getMail(mails, indice) = 0;
}

/**********************************************************/

/*
  Retourne l'indice du premier emplacement libre dans 
  le tableau mails contenant nbMax adresses. On suppose que le tableau 
  n'est pas plein.
*/

int indicePremiereChaineVide(char* mails, int indiceMax)
{
  int milieu;
  if (indiceMax == 0)
    return 0;
  milieu = indiceMax / 2;
  if (!*getMail(mails, milieu))
    return indicePremiereChaineVide(mails, milieu);
  else
    return milieu + 1 + 
      indicePremiereChaineVide(getMail(mails, milieu + 1), 
			       indiceMax - (milieu + 1));
}

/**********************************************************/

/*
  Trie le tableau mails contenant (indice + 1) elements, 
  ne fonctionne que si tous les autres elements
  sont tries. 
*/

void placeMail(char* mails, int indice)
{
  if (indice > 0 && indice < NB_MAILS &&
      strncmp(getMail(mails, indice),
	      getMail(mails, indice - 1), 
	      SIZE_MAIL) < 0)
    {
      swapStrings(getMail(mails, indice),
		  getMail(mails, indice - 1),
		  SIZE_MAIL);
      placeMail(mails, indice - 1);
    }
  else
    if (indice >= 0 && indice < NB_MAILS - 1 &&
	*getMail(mails, indice + 1) &&
	strncmp(getMail(mails, indice),
		getMail(mails, indice + 1), 
		SIZE_MAIL) > 0)
      {
	swapStrings(getMail(mails, indice),
		    getMail(mails, indice + 1),
		    SIZE_MAIL);
	placeMail(mails, indice + 1);
      }
}

/**********************************************************/

void ajouteMail(char* mails, char* mail)
{
  int indice;
  if (*getMail(mails, NB_MAILS - 1))
    {
      printf("Carnet de contact plein.\n");
    }
  else
    {
      indice = indicePremiereChaineVide(mails, NB_MAILS - 1);      
      strncpy(getMail(mails, indice), mail, SIZE_MAIL);
      *(getMail(mails, indice) + SIZE_MAIL - 1) = 0;
      placeMail(mails, indice);
    }
}

/**********************************************************/

void changeMail(char* mails, char* mail, int indice)
{
  strncpy(getMail(mails, indice), mail, SIZE_MAIL);
  *(getMail(mails, indice) + SIZE_MAIL - 1) = 0;
  placeMail(mails, indice);
}

/**********************************************************/

void sauvegardeMails(char* mails, char* nomFichier)
{
  FILE* f = fopen(nomFichier, "w");
  int i;
  if (f == NULL)
    printf("Impossible d'ouvrir le fichier %s", nomFichier);
  else
    for(i = 0 ; i < NB_MAILS && *getMail(mails, i) ; i++)
      fwrite(getMail(mails, i), sizeof(char), SIZE_MAIL, f);
  fclose(f);
}

/**********************************************************/

void restaureMails(char* mails, char* nomFichier)
{
  FILE* f = fopen(nomFichier, "r");
  int i, ret = 1;
  if (f == NULL)
    printf("Impossible d'ouvrir le fichier %s", nomFichier);
  else
    for(i = 0 ; i < NB_MAILS && ret ; i++)
      ret = fread(getMail(mails, i), sizeof(char), SIZE_MAIL, f);
  fclose(f);  
}

#include<stdio.h>
#include<stdlib.h>

#include"util.h"
#include"tableau.h"

#define AFFICHER_OPTION 1
#define SUPPRIMER_OPTION 2
#define MODIFIER_OPTION 3
#define AJOUTER_OPTION 4
#define QUITTER_OPTION 5
#define NB_OPTIONS 5

#define F_NAME ".adressesMails.txt"

/**********************************************************/

/*
  Affiche le menu principal.
*/

void afficheMenu()
{
  printf("\nOptions disponibles :\n"
	 "%d - afficher les contacts\n"
	 "%d - supprimer un contact\n"
	 "%d - modifier un contact\n"
	 "%d - ajouter un contact\n"
	 "%d - quitter\n",
	 AFFICHER_OPTION, 
	 SUPPRIMER_OPTION,
	 MODIFIER_OPTION,
	 AJOUTER_OPTION,
	 QUITTER_OPTION);
}

/**********************************************************/

/*
  Affiche le menu principal, retourne la valeur saisie par 
  l'utilisateur.
*/

int choisitOptionMenu()
{
  int option;
  do
    {
      afficheMenu();
      printf("Choisissez une option en saisissant son numero : ");
      option = getInt();
      if (option <= 0 && option > NB_OPTIONS)
	printf("option invalide\n");
    }
  while(option <= 0 && option > NB_OPTIONS);
  return option;
}

/**********************************************************/

/*
  Demande a l'utilisateur de saisir un mail, le place 
  a l'adresse adr.
*/

void saisitMail(char* adr)
{
  printf("Veuillez saisir l'adresse e-mail de votre contact : ");
  do
    {
      getString(adr, SIZE_MAIL);
      if (!*adr)
	printf("Vous devez saisir une adresse");
    }
  while(!*adr);
}

/**********************************************************/

/*
  Affiche la liste de mails, saisit et retourne le numero de 
  l'un d'eux. 
*/

int choisitMail(char* mails)
{
  int i, nbMails;
  nbMails = nombreMails(mails);
  afficheMails(mails);
  do
    {
      printf("Choisissez un mail en saisissant son numero : ");
      i = getInt();
      if (i <= 0 && i > nbMails)
	printf("Cet indice n'existe pas ! \n");
    }
  while(i <= 0 && i > nbMails);
  return i - 1;  
}

/**********************************************************/

/*
  Saisit un mail m et un indice i, puis remplace le i-eme mail 
  de mails par m.
*/

void modifierOption(char* mails)
{
  int i;
  char m[SIZE_MAIL];
  printf("Modification d'un contact : \n");
  i = choisitMail(mails);
  saisitMail(m);
  changeMail(mails, m, i);
}

/**********************************************************/

/*
  Saisit un mail m et un indice i, puis remplace le i-eme mail 
  de mails par m.
*/

void ajouterOption(char* mails)
{
  char m[SIZE_MAIL];
  printf("Ajout d'un contact : \n");
  saisitMail(m);
  ajouteMail(mails, m);
}

/**********************************************************/

/*
  Saisit un indice i, puis supprime le i-eme mail dans mails. 
*/

void supprimerOption(char* mails)
{
  int i;
  printf("Suppression d'un contact : \n");
  i = choisitMail(mails);
  supprimeMail(mails, i);
}

/**********************************************************/

/*
  Sauve les mails dans le fichier F_NAME et affiche un message 
  d'adieu.
*/

void quitterOption(char* mails)
{
  sauvegardeMails(mails, F_NAME);
  printf("Au revoir !\n");  
}

/**********************************************************/

/*
  Affiche le menu principal, saisit une option, et effectue le 
  traitement necessaire. 
*/

void executeMenu(char* mails)
{
  int option;
  do
    {
      option = choisitOptionMenu();
      switch(option)
	{
	case AFFICHER_OPTION : 
	  afficheMails(mails);
	  break;
	case AJOUTER_OPTION : 
	  ajouterOption(mails);
	  break;
	case MODIFIER_OPTION : 
	  modifierOption(mails);
	  break;
	case SUPPRIMER_OPTION : 
	  supprimerOption(mails);
	  break;
	case QUITTER_OPTION : 
	  quitterOption(mails);
	  break;
	default:
	  break;
	}
    }
  while(option != QUITTER_OPTION);
}

/**********************************************************/

int main()
{
  char* mails = creerMails();
  restaureMails(mails, F_NAME);
  executeMenu(mails);
  detruitMails(mails);
  return 0;
}

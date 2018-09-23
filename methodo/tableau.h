#ifndef TABLEAU_H
#define TABLEAU_H

#define SIZE_MAIL 30
#define NB_MAILS 6

/*
  Implemente un carnet de contacts a l'aide d'un tableau.
  Une case inoccupee est representee par une chaine vide, 
  toutes les adresses sont disposees par ordre alphabetique 
  au debut du tableau. 
 */

/**********************************************************/

/*
  Affiche le carnet de contacts. 
*/

void afficheMails(char* mails);

/**********************************************************/

/*
  Retourne l'adresse du i-eme mail.
*/

char* getMail(char* mails, int i);
 
/**********************************************************/

/*
  Retourne le nombre de contacts.
*/

int nombreMails(char* mails);

/*****************************************************/

/*
  Creee un tableau de d'e-mails et le retourne. Ce tableau contient 
  NB_MAILS chaines de capacites longueur SIZE_MAIL initialises 
  avec des chaines vides. 
*/

char* creerMails();

/*****************************************************/

/*
  Libere la memoire
*/

void detruitMails(char* mails);

/**********************************************************/

/*
  Supprime l'adresse dont l'indice est passe en parametre.
*/

void supprimeMail(char* mails, int indice);

/**********************************************************/

/*
  Ajoute le mail mail dans le tableau mails.
*/

void ajouteMail(char* mails, char* mail);

/**********************************************************/

/*
  Remplace le indice-eme mail du tableau mails par mail. L'indice
  est suppose valide. 
*/

void changeMail(char* mails, char* mail, int indice);

/**********************************************************/

/*
  Ecrit tous les contacts de mails dans le fichier nomFichier.
*/

void sauvegardeMails(char* mails, char* nomFichier);

/**********************************************************/

/*
  Lit tous les contacts de mails dans le fichier nomFichier.
*/

void restaureMails(char* mails, char* nomFichier);

#endif 


#include<stdio.h>

/*
  Affiche le caractere c
 */

void afficheCaractere(char c)
{
}

/*****************************************/

/*
  affiche n fois le caractere c, ne revient pas a la ligne 
  apres le dernier caractere.
*/

void ligneSansReturn(int n, char c)
{
}

/*****************************************/

/*
  affiche n fois le caractere c, revient a la ligne apres 
  le dernier caractere.
*/

void ligneAvecReturn(int n, char c)
{
}

/*****************************************/

/*
  Affiche n espaces.
*/

void espaces(int n)
{
}

/*****************************************/

/*
  Affiche le caractere c a la colonne i, 
  ne revient pas a la ligne apres.
*/

void unCaractereSansReturn(int i, char c)
{
}

/*****************************************/

/*
  Affiche le caractere c a la colonne i, 
  revient a la ligne apres.
*/

void unCaractereAvecReturn(int i, char c)
{
}

/*****************************************/

/*
  Affiche le caractere c aux colonnes i et j, 
  revient a la ligne apres.
*/

void deuxCaracteres(int i, int j, char c)
{
}

/*****************************************/

/*
  Affiche un carre de cote n.
*/

void carre(int n)
{
}

/*****************************************/

/*
  Affiche un chapeau dont la pointe - non affichee - est 
  sur la colonne centre, avec les caracteres c.
*/

void chapeau(int centre, char c)
{
}

/*****************************************/

/*
  Affiche un chapeau a l'envers avec des caracteres c, 
  la pointe - non affichee - est a la colonne centre
*/

void chapeauInverse(int centre, char c)
{
}

/*****************************************/

/*
  Affiche un losange de cote n.
*/

void losange(int n)
{
}

/*****************************************/

/*
  Affiche une croix de cote n
*/

void croix(int n)
{
}

/*****************************************/

main()
{
      int taille;
      printf("Saisissez la taille des figures\n");
      scanf("%d", &taille);
      carre(taille);
      losange(taille);
      croix(taille);
}

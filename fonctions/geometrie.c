#include<stdio.h>

/*
  Affiche le caractere c
 */

void afficheCaractere(char c)
{
     printf("%c ", c);
}

/*****************************************/

/*
  affiche n fois le caractere c, ne revient pas a la ligne 
  apres le dernier caractere.
*/

void ligneSansReturn(int n, char c)
{
     int i;
     for(i = 1 ; i <= n ; i++)
           afficheCaractere(c);
}

/*****************************************/

/*
  affiche n fois le caractere c, revient a la ligne apres 
  le dernier caractere.
*/

void ligneAvecReturn(int n, char c)
{
     ligneSansReturn(n, c);
     printf("\n");
}

/*****************************************/

/*
  Affiche n espaces.
*/

void espaces(int n)
{
     ligneSansReturn(n, ' '); 
}

/*****************************************/

/*
  Affiche le caractere c a la colonne i, 
  ne revient pas a la ligne apres.
*/

void unCaractereSansReturn(int i, char c)
{
     espaces(i - 1);
     printf("%c ", c);
}

/*****************************************/

/*
  Affiche le caractere c a la colonne i, 
  revient a la ligne apres.
*/

void unCaractereAvecReturn(int i, char c)
{
     unCaractereSansReturn(i, c);
     printf("\n");
}

/*****************************************/

/*
  Affiche le caractere c aux colonnes i et j, 
  revient a la ligne apres.
*/

void deuxCaracteres(int i, int j, char c)
{
     int k;
     if (i > j)
           deuxCaracteres(j, i, c);
     else 
     {
         if (i != j)
         {
               unCaractereSansReturn(i, c);
               unCaractereAvecReturn(j - i, c);
         }
         else
               unCaractereAvecReturn(i, c);
     }         
}

/*****************************************/

/*
  Affiche un carre de cote n.
*/

void carre(int n)
{
     int k; 
     ligneAvecReturn(n, '*');
     for(k = 2 ; k <= n - 1 ; k++)
           deuxCaracteres(1, n, '*');
     ligneAvecReturn(n, '*');     
}

/*****************************************/

/*
  Affiche un chapeau dont la pointe - non affichee - est 
  sur la colonne centre, avec les caracteres c.
*/

void chapeau(int centre, char c)
{
     int k;
     int delta;
     for (k = 2 ; k <= centre - 1 ; k++)
     {
         delta = k - 1;     
         deuxCaracteres(centre - delta, centre + delta, '*');
     }
}

/*****************************************/

/*
  Affiche un chapeau a l'envers avec des caracteres c, 
  la pointe - non affichee - est a la colonne centre
*/

void chapeauInverse(int centre, char c)
{
     int k;
     int delta;
     for (k = centre - 1 ; k >= 2; k--)
     {
         delta = k - 1;     
         deuxCaracteres(centre - delta, centre + delta, '*');
     }
}

/*****************************************/

/*
  Affiche un losange de cote n.
*/

void losange(int n)
{
     unCaractereAvecReturn(n, '*');
     chapeau(n, '*');
     deuxCaracteres(1, 2*n - 1, '*');
     chapeauInverse(n, '*');
     unCaractereAvecReturn(n, '*');
}

/*****************************************/

/*
  Affiche une croix de cote n
*/

void croix(int n)
{
     deuxCaracteres(1, 2*n - 1, '*');
     chapeauInverse(n, '*');
     unCaractereAvecReturn(n, '*');
     chapeau(n, '*');
     deuxCaracteres(1, 2*n - 1, '*');
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

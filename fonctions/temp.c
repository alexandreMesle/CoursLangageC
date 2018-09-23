#include<stdio.h>
//#include<stdlib.h>

void afficheCaractere(char c)
{
     printf("%c ", c);
}

void ligneSansReturn(int n, char c)
{
     int i;
     for(i = 1 ; i <= n ; i++)
           afficheCaractere(c);
}
void ligneAvecReturn(int n, char c)
{
     ligneSansReturn(n, c);
     printf("\n");
}

void espaces(int n)
{
     ligneSansReturn(n, ' '); 
}

void unCaractereSansReturn(int i, char c)
{
     espaces(i - 1);
     printf("%c ", c);
}

void unCaractereAvecReturn(int i, char c)
{
     unCaractereSansReturn(i, c);
     printf("\n");
}

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

void carre(int n)
{
     int k; 
     ligneAvecReturn(n, '*');
     for(k = 2 ; k <= n - 1 ; k++)
           deuxCaracteres(1, n, '*');
     ligneAvecReturn(n, '*');     
}

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

void losange(int n)
{
     unCaractereAvecReturn(n, '*');
     chapeau(n, '*');
     deuxCaracteres(1, 2*n - 1, '*');
     chapeauInverse(n, '*');
     unCaractereAvecReturn(n, '*');
}

void croix(int n)
{
     deuxCaracteres(1, 2*n - 1, '*');
     chapeauInverse(n, '*');
     unCaractereAvecReturn(n, '*');
     chapeau(n, '*');
     deuxCaracteres(1, 2*n - 1, '*');
}

main()
{
      int taille;
      printf("Saisissez la taille des figures\n");
      scanf("%d", &taille);
      carre(taille);
      losange(taille);
      croix(taille);
      //getch();
}

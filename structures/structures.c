#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAILLE_NOM 50
#define TAILLE_TEL 10
#define NB_MAX_NOMS 500

/***************************************************************/

struct personne
{
       char nom[TAILLE_NOM+1];
       char tel[TAILLE_TEL+1];
};

/***************************************************************/

void affichePersonne(struct personne p)
{
     printf("%s : %s\n", p.nom, p.tel);
}

/***************************************************************/

// Affiche toutes les entrées dont le nom ne commence pas
// par un caractère nul.
void afficheRepertoire(struct personne r[])
{
     int i = 0;
     while(i < NB_MAX_NOMS && r[i].nom[0] != 0)
         {
            printf("%d ", i);
            affichePersonne(r[i]);
            i++;
         }
}

/***************************************************************/

// Un enregistrement est vide si le nom commence par le caractère nul.
// Cette fonction initialise le répertoire.
void initRepertoire(struct personne rep[])
{
     int i;
     for (i = 0 ; i < NB_MAX_NOMS ; i++)
         rep[i].nom[0] = 0;
}

/***************************************************************/

// retourne un nombre positif si la première personne a une clé
// supérieure à celle de la deuxième personne.

int comparePersonnes(struct personne p, struct personne q)
{
   return strncmp(p.nom, q.nom, TAILLE_NOM);
}

/***************************************************************/

void decalageDroite(struct personne rep[], int inf, int sup)
{
     int i;
     for (i = sup ; i >= inf ; i--)
         rep[i+1] = rep[i];
}

/***************************************************************/

void decalageGauche(struct personne rep[], int inf, int sup)
{
     int i;
     for (i = inf ; i <= sup ; i++)
         rep[i-1] = rep[i];
}

/***************************************************************/

// Retourne l'indice du premier élément disponible dans le tableau. -1 si le répertoire est plein.
int trouveFin(struct personne rep[])
{
     int i = 0;
     while(i < NB_MAX_NOMS && rep[i].nom[0] != 0)
            i++;
     if (i != NB_MAX_NOMS)
          return i;
     return -1;
}

/***************************************************************/

// Ajoute une personne au répertoire, le maintient trié.
int ajouteStructPersonne(struct personne rep[], struct personne p)
{
     int sup = trouveFin(rep);
     int inf = 0;
     if (sup == -1)
        return -1;
     while(inf < sup && (comparePersonnes(p, rep[inf])>0))
            inf++;
     decalageDroite(rep, inf, sup - 1);
     rep[inf] = p;
     return 1;
}

/***************************************************************/

// Ajoute une personne au répertoire.
int ajoutePersonne(struct personne r[], char nom[], char tel[])
{
     struct personne p;
     strncpy(p.nom, nom, TAILLE_NOM);
     strncpy(p.tel, tel, TAILLE_TEL);
     p.nom[TAILLE_NOM] = 0;
     p.tel[TAILLE_TEL] = 0;
     return ajouteStructPersonne(r, p);
}

/***************************************************************/

// Affiche toutes les personnes dont le nom commence par débutNom.
void trouvePersonnes(struct personne r[], char debutNom[])
{
  int i;
  for (i = 0 ; i < NB_MAX_NOMS ; i++)
      if (r[i].nom[0] != 0 &&
      !strncmp(r[i].nom, debutNom, strlen(debutNom)))
      {
          printf("%d ", i);
          affichePersonne(r[i]);
      }
}

/***************************************************************/

// Echange les enregistrement d'indices i et j.
void echangePersonnes(struct personne r[], int i, int j)
{
     struct personne p;
     p = r[i];
     r[i] = r[j];
     r[j] = p;
}

/***************************************************************/

// En cas de changement de nom, permute l'élément d'indice i avec ses voisins
// jusqu'à ce que le tableau soit trié.
void triLocal(struct personne r[], int indice)
{
     if (indice > 0 && comparePersonnes(r[indice - 1], r[indice]) > 0)
     {
                echangePersonnes(r, indice - 1, indice);
                triLocal(r, indice - 1);
     }
     if (indice < NB_MAX_NOMS - 1 && r[indice + 1].nom[0]!=0
        && comparePersonnes(r[indice], r[indice + 1]) > 0)
     {
                echangePersonnes(r, indice, indice + 1);
                triLocal(r, indice + 1);
     }
}

/***************************************************************/

// Remplace le nom d'indice indice par nouveauNom, puis trie le tableau.
void changeNom(struct personne r[], int indice, char nouveauNom[])
{
     strncpy(r[indice].nom, nouveauNom, TAILLE_NOM);
     r[indice].nom[TAILLE_NOM] = 0;
     triLocal(r, indice);
}

/***************************************************************/

// Remplace le numéro d'indice indice par nouveauNuméro.
void changeNumero(struct personne r[], int indice, char nouveauTel[])
{
     strncpy(r[indice].tel, nouveauTel, TAILLE_TEL);
     r[indice].tel[TAILLE_TEL] = 0;         
}

/***************************************************************/

// Supprime la personne d'indice indice, décale les éléments suivants pour
// éviter les "trous" dans le tableau.
void supprimePersonne(struct personne r[], int indice)
{
     int sup = trouveFin(r);
     int inf = indice;
     decalageGauche(r, inf + 1, sup - 1);
     r[sup - 1].nom[0] = 0;
}

/***************************************************************/

main()
{
      struct personne repertoire[NB_MAX_NOMS];
      initRepertoire(repertoire);
      ajoutePersonne(repertoire, "toto", "0123456789");
      ajoutePersonne(repertoire, "tyty", "0123456789");
      ajoutePersonne(repertoire, "titi", "0123456789");
      ajoutePersonne(repertoire, "tata", "0123456789");
      ajoutePersonne(repertoire, "tutu", "0123456789");
      afficheRepertoire(repertoire);
      supprimePersonne(repertoire, 2);
      afficheRepertoire(repertoire);     
      getch();
}

 

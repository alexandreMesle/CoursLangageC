#include<stdio.h>
#include<stdlib.h>

/*
  Dans toutes les fonctions à partir d'insere, il est interdit de
  creer des maillons, toutes ces operations doivent se faire 
  par modification du chainage et non par recopie.
*/

typedef struct lls
{
  int data;
  struct lls* next;
}ll;

/********************************************************/

/*
  Alloue dynamiquement et initialise un maillon avec les 
  valeurs data et next, retourne son adresse.
*/

ll* cree(int data, ll* next)
{
  ll* maillon = (ll*)malloc(sizeof(ll));
  if (maillon == NULL)
  {
    printf("Plus de mémoire");
    exit(1);
  }
  maillon->data = data;
  maillon->next = next;
  return maillon;
}

/********************************************************/

/*
  Affiche le maillon l
*/

void affiche(ll* l)
{
  printf("%d -> ", l->data);
}

/********************************************************/

/*
  Affiche, dans l'ordre, tous les maillons de la liste l.
*/

void afficheTout(ll* l)
{ 
  if (l != NULL)
    {
      affiche(l);
      afficheTout(l->next);
    }
  else
    printf("\n");
}

/********************************************************/

/*
  Affiche en partant de la fin tous les maillons 
  de la liste l.
*/

void afficheALEnvers(ll* l)
{
  if (l != NULL)
    {
      afficheALEnvers(l->next);
      affiche(l);
    }
}

/********************************************************/

/*
  Detruit tous les maillons de la liste *l, met ce pointeur 
  a NULL.
*/

void detruit(ll* l)
{
  if (l != NULL)
    {
      detruit(l->next);
      free(l);
    }
}

/********************************************************/

/*
  Retourne la liste n -> n-1 -> ... -> 2 -> 1
*/

ll* entiersALEnvers(int n)
{
  if (n < 1)
    return NULL;
  return cree(n, entiersALEnvers(n - 1));
}

/********************************************************/

/*
  Retourne la liste 1 -> 2 -> ... -> n
*/

ll* entiers(int n)
{
  return NULL;
}

/********************************************************/

/*
  Insere le maillon x dans la liste l, supposee triee.
*/

ll* insere(ll* l, ll* x)
{
  return NULL;
}

/********************************************************/

/*
  Tri la liste l avec la methode du tri par insertion, retourne
  l'adresse du premier element de la liste triee.
*/

ll* triInsertion(ll* l)
{
  return NULL;
}

/********************************************************/

/*
  Repartit les elements de l entre les listes l1 et l2. 
  ex : l = 1 -> 2 -> 3 -> 4 -> 5 nous donne
  l1 = 5 -> 3 -> 1et l2 = 4 -> 2
*/

void split(ll* l, ll** l1, ll** l2)
{
}

/********************************************************/

/*
  Retourne l'interclassement des listes l1 et l2, supposees triees.
*/

ll* interclasse(ll* l1, ll* l2)
{
  return NULL;
}

/********************************************************/

/*
  Trie l avec la methode du tri fusion, retorune l'adresse
  du premier element de la liste triee.
*/

ll* triFusion(ll* l)
{
  return NULL;
}

/********************************************************/

/*
  Pour tester les fonctions...
*/

int main()
{
  ll* maillon = entiersALEnvers(10);
  afficheTout(maillon);
  afficheALEnvers(maillon);
  detruit(maillon);
  return 0;
}

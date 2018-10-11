#include<stdio.h>
#include<stdlib.h>

/*
  Dans toutes les fonctions a partir d'insere, il est interdit de
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

ll* creer(int data, ll* next)
{
  ll* l = (ll*)malloc(sizeof(ll));
  if (l == NULL)
    {
      printf("heap overflow\n,");
      exit(0);
    }
  l->data = data;
  l->next = next;
  return l;
}

/********************************************************/

/*
  Affiche le maillon l
*/

void affiche(ll* l)
{
  if (l != NULL)
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

void detruit(ll** l)
{
  if (*l != NULL)
    {
      detruit(&((*l)->next));
      free(*l);
      *l = NULL;
    }
}

/********************************************************/

/*
  Retourne la liste n -> n-1 -> ... -> 2 -> 1
*/

ll* entiersALEnvers(long n)
{
  if (n > 0)
    return creer(n, entiersALEnvers(n - 1));
  else
    return NULL;
}

/********************************************************/

/*
  Pour la fonction suivante....
 */

ll* entiersT(long n, ll* acc)
{
  if (n > 0)
    return entiersT(n - 1, creer(n, acc));
  else 
    return acc;
}

/*
  Retourne la liste 1 -> 2 -> ... -> n
*/

ll* entiers(long n)
{
  return entiersT(n, NULL);
}

/********************************************************/

/*
  Insere le maillon x dans la liste l, supposee triee.
*/

ll* insere(ll* l, ll* x)
{
  if (l == NULL  || x->data <= l->data)
    {
      x->next = l;
      return x;
    }
  l->next = insere(l->next, x);
  return l;
}

/********************************************************/

/*
  Tri la liste l avec la methode du tri par insertion, retourne
  l'adresse du premier element de la liste triee.
*/

ll* triInsertion(ll* l)
{
  if (l == NULL)
    return NULL;
  return insere(triInsertion(l->next), l);
}

/********************************************************/

/*
  Repartit les elements de l entre les listes l1 et l2. 
  ex : l = 1 -> 2 -> 3 -> 4 -> 5 nous donne
  l1 = 1 -> 3 -> 5 et l2 = 2 -> 4
*/

void split(ll* l, ll** l1, ll** l2)
{
  if (l != NULL)
    {
      split(l->next, l2, l1);
      l->next = *l1;
      *l1 = l;
    }
}

/********************************************************/

/*
  Retourne l'interclassement des listes l1 et l2, supposees triees.
*/

ll* interclasse(ll* l1, ll* l2)
{
  if (l1 == NULL)
    return l2;
  if (l2 == NULL)
    return l1;
  if (l1->data < l2->data)
    {
      l1->next = interclasse(l1->next, l2);
      return l1;
    }
  else
    {
      l2->next = interclasse(l1, l2->next);
      return l2;
    }
}

/********************************************************/

/*
  Trie l avec la methode du tri fusion, retorune l'adresse
  du premier element de la liste triee.
*/

ll* triFusion(ll* l)
{
  if (l == NULL || l->next == NULL)
    return l;
  else
    {
      ll *l1 = NULL, *l2 = NULL;
      split(l, &l1, &l2);
      l1 = triFusion(l1); 
      l2 = triFusion(l2);
      return interclasse(l1, l2);
    }
}

/********************************************************/

/*
  Pour tester les fonctions...
*/

int main()
{
  long n = 50000;
  ll* l = entiersALEnvers(n), *m = entiersALEnvers(n);
  printf("tri fusion\n");
  l = triFusion(l); 
  printf("ok\n");
  detruit(&l);
  printf("tri insertion\n"); 
  m = triInsertion(m);
  printf("ok\n");
  detruit(&m);
  return 0;
}


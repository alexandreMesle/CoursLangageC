#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define N 10

/**************************************************************/
typedef struct dmaillon
{
  int data;
  struct dmaillon* previous;
  struct dmaillon* next;
}dmaillon;

/**************************************************************/

typedef struct dLinkedList
{
  struct dmaillon* first;
  struct dmaillon* last;
}dLinkedList;

/**************************************************************/

/*
  Affiche les elements d'une liste chainee.
 */

void printDLL(dLinkedList* dl)
{
}

/**************************************************************/

/*
  Libere tous les maillons, puis libere dl.
 */

void freeDLL(dLinkedList* dl)
{
}

/**************************************************************/

/*
  Alloue la memoire pour une dLinkedList, 
  initialise les pointeurs a NULL   
*/

dLinkedList* makeDLL()
{
  return NULL;
}

/**************************************************************/

/*
  Cree un maillon contenant la valeur n.
 */

dmaillon* makeDMaillon(int n)
{
  return NULL;
  
}

/**************************************************************/

/*
  Accroche le maillon m a la fin de la liste chainee dl
 */

void appendDMaillonDLL(dLinkedList* dl, dmaillon* m)
{
}

/**************************************************************/

/*
  Accroche le maillon m au debut de la liste chainee dl
 */

void pushDMaillonDLL(dLinkedList* dl, dmaillon* m)
{
}

/**************************************************************/

/*
  Ajoute a la fin de dl un maillon contenant la valeur n.
 */

void appendIntDLL(dLinkedList* dl, int n)
{
}

/**************************************************************/

/*
  Ajoute au debut de dl un maillon contenant la valeur n.
 */

void pushIntDLL(dLinkedList* dl, int n)
{
}

/**************************************************************/

/*
  Place dans la liste doublement chainee 
  les valeurs {0, ..., n}
 */

void initDLL(dLinkedList* dl, int n)
{
}

/**************************************************************/

/*
  Inverse l'ordre des elements de dl.
 */

void reverseDLL(dLinkedList* dl)
{
}

/**************************************************************/

/*
  Retourne une copie de source.
 */

dLinkedList* copyDLL(dLinkedList* source)
{
  return NULL;
}

/**************************************************************/

/*
  Concatene fin a la suite de debut, vide la liste fin.
 */

void concatDLL(dLinkedList* debut, dLinkedList* fin)
{
}

/**************************************************************/

int main()
{
  return 0;
}

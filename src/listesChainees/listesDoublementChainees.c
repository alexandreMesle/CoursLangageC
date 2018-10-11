#include<stdio.h>
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
  dmaillon* m ;
  for(m = dl->first; m != NULL ; m = m->next)
    printf("%d -> ", m->data);
  printf("\n");
}

/**************************************************************/

/*
  Libere tous les maillons, puis libere dl.
 */

void freeDLL(dLinkedList* dl)
{
  dmaillon* m;
  dmaillon* next;
  for (m = dl->first; m != NULL ; m = next)
    {
      next = m->next;
      free(m);
    }
  free(dl);
}

/**************************************************************/

/*
  Alloue la memoire pour une dLinkedList, 
  initialise les pointeurs a NULL   
*/

dLinkedList* makeDLL()
{
  dLinkedList* l;
  l = (dLinkedList*)malloc(sizeof(dLinkedList)); 
  if(l == NULL)
    {
      printf("Plus de mémoire");
      return NULL;
    }
  l->first = NULL;
  l->last = NULL;
  return l;
}

/**************************************************************/

/*
  Cree un maillon contenant la valeur n.
 */

dmaillon* makeDMaillon(int n)
{
  dmaillon* d;
  d = (dmaillon*)malloc(sizeof(dmaillon)); 
  if(d == NULL)
    exit(0);
  d->previous = NULL;
  d->next = NULL;
  d->data = n;
  return d;
  
}

/**************************************************************/

/*
  Accroche le maillon m a la fin de la liste chainee dl
 */

void appendDMaillonDLL(dLinkedList* dl, dmaillon* m)
{
  if (dl->last == NULL)
    {
      dl->first = m; 
      dl->last = m;
    }
  else
    {
      dl->last->next = m;
      m->previous = dl->last;
      dl->last = m;
    }
  dl->first->previous = NULL;
  dl->last->next = NULL;
}

/**************************************************************/

/*
  Accroche le maillon m au debut de la liste chainee dl
 */

void pushDMaillonDLL(dLinkedList* dl, dmaillon* m)
{
  if (dl->last == NULL)
    {
      dl->first = m; 
      dl->last = m;
    }
  else
    {
      dl->first->previous = m;
      m->next = dl->first;
      dl->first = m;
    }
  dl->first->previous = NULL;
  dl->last->next = NULL;
}

/**************************************************************/

/*
  Ajoute a la fin de dl un maillon contenant la valeur n.
 */

void appendIntDLL(dLinkedList* dl, int n)
{
  appendDMaillonDLL(dl, makeDMaillon(n));
}

/**************************************************************/

/*
  Ajoute au debut de dl un maillon contenant la valeur n.
 */

void pushIntDLL(dLinkedList* dl, int n)
{
  pushDMaillonDLL(dl, makeDMaillon(n));
}

/**************************************************************/

/*
  Place dans la liste doublement chainee 
  les valeurs {0, ..., n}
 */

void initDLL(dLinkedList* dl, int n)
{
  int i;
  for(i = 0 ; i < n ; i++)
    appendIntDLL(dl, i);
}

/**************************************************************/

/*
  Inverse l'ordre des elements de dl.
 */

void reverseDLL(dLinkedList* dl)
{
  dmaillon* m ;
  dmaillon* temp;
  if (dl->first != NULL)
    {
      for(m = dl->first; m != NULL ; m = m->previous)
	{
	  temp = m->previous;
	  m->previous = m->next;
	  m->next = temp;	    
	}
    }
  temp = dl->first;
  dl->first = dl->last;
  dl->last = temp;
}

/**************************************************************/

/*
  Retourne une copie de source.
 */

dLinkedList* copyDLL(dLinkedList* source)
{
  dLinkedList* dest = makeDLL();
  dmaillon* sourceMaillon;
  for(sourceMaillon = source->first; sourceMaillon != NULL ;
      sourceMaillon = sourceMaillon->next)
    appendIntDLL(dest, sourceMaillon->data);
  return dest;
}

/**************************************************************/

/*
  Concatene fin a la suite de debut, vide la liste fin.
 */

void concatDLL(dLinkedList* debut, dLinkedList* fin)
{
  if (debut->first == NULL)
    {
      debut->first = fin->first;
      debut->last = fin->last;
    }
  else
    {
      debut->last->next = fin->first;
      if (fin->first != NULL)
	fin->first->previous = debut->last;
      debut->last = fin->last;
    }
  fin->first = NULL;
  fin->last = NULL;
}

/**************************************************************/

int main()
{
  dLinkedList* dl = makeDLL();
  dLinkedList* cp;
  initDLL(dl, N);
  printDLL(dl);
  cp = copyDLL(dl);
  printDLL(cp);
  reverseDLL(cp);
  printDLL(cp);
  concatDLL(dl, cp);
  printDLL(dl);
  freeDLL(dl);
  freeDLL(cp);
  return 0;
}

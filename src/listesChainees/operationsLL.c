#include<stdio.h>
#include<stdlib.h>

#define N 10

/**************************************************************/

typedef struct maillon
{
  int data;
  struct maillon* next;
}maillon;

/**************************************************************/

void printLL(maillon* ptr)
{
  for( ; ptr != NULL ; ptr = ptr->next)
    printf("data = %d\n", ptr->data);
}

/**************************************************************/

maillon* creeMaillon(int n)
{
  maillon* l;
  l = (maillon*)malloc(sizeof(maillon));
  if(l == NULL)
    {
      printf("Impossible de créer un maillon.");
      return NULL;
    }
  l->data = n;
  l->next = NULL;
  return l;
}

/**************************************************************/

maillon* insereFinLL(maillon* l, int n)
{
  maillon* last = creeMaillon(n);
  maillon* first = l;
  if (l == NULL)
    return last;
  else
    {	
      while(l->next != NULL)
	l = l->next;
      l->next = last;
    }
  return first;
}

/**************************************************************/

maillon* copyLL(maillon* source)
{
  maillon* copie;
  maillon* maillonCopie;
  if (source == NULL)
    return NULL;
  copie = creeMaillon(source->data);
  maillonCopie = copie;
  source = source->next;
  while(source != NULL)
    {
      maillonCopie->next = creeMaillon(source->data);
      maillonCopie = maillonCopie->next;
      source = source->next;
    }
  maillonCopie->next = NULL;
  return copie;
}

/**************************************************************/

maillon* reverseLL(maillon* l)
{
  maillon* previous;
  maillon* current;
  maillon* next;
  if (l == NULL)
    return NULL;
  current = l->next;
  l->next = NULL;
  previous = l;
  next = current;
  while(current != NULL)
    {
      if(next != NULL)
	next = next->next;
      current->next = previous;
      previous = current;
      current = next;
    }
  return previous;
}

/**************************************************************/

maillon* insereDebutLL(maillon* l, int n)
{
  maillon* first = creeMaillon(n);
  first->next = l;
  return first;
}

/**************************************************************/

maillon* initLL(int n)
{
  maillon* l = NULL;
  int i;
  for(i = n - 1 ; i >= 0 ; i--)
    l = insereDebutLL(l, i);
  return l;
}

/**************************************************************/

void freeLL(maillon* l)
{
  maillon* n;
  while(l != NULL)
    {
      n = l->next;
      free(l);
      l = n;
    }
}

/**************************************************************/

int main()
{
  maillon* l;
  maillon* k;
  l = initLL(N);
  printLL(l);
  k = copyLL(l);
  k = reverseLL(k);
  printLL(k);  
  freeLL(l);
  freeLL(k);
  return 0;
}

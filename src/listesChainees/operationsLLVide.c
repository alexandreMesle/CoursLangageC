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
    exit(0);
  l->data = n;
  l->next = NULL;
  return l;
}

/**************************************************************/

maillon* insereFinLL(maillon* l, int n)
{
  return NULL;
}

/**************************************************************/

maillon* copyLL(maillon* source)
{
  return NULL;
}

/**************************************************************/

maillon* reverseLL(maillon* l)
{
  return NULL;
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
  return 0;
}

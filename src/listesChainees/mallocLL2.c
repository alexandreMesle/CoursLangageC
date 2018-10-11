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

maillon* initLL(int n)
{
  maillon* first;
  maillon* current;
  maillon* previous;
  int i;
  first = (maillon*)malloc(sizeof(maillon));
  if(first == NULL)
    return NULL;
  first->data = 0;
  previous = first;
  for(i = 1 ; i < n ; i++)
    {
      current = (maillon*)malloc(sizeof(maillon));
      if(current == NULL)
	exit(0);
      current->data = i;
      previous->next = current;
      previous = current;
    }
  current->next = NULL;
  return first;
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
  l = initLL(N);
  if (l == NULL)
    return -1;
  printLL(l);
  freeLL(l);
  return 0;
}

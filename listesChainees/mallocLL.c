#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define N 10

/**************************************************************/

typedef struct maillon
{
        int data;
        struct maillon* next;
}maillon;

void printData(maillon* ptr)
{
  for( ; ptr != NULL ; ptr = ptr->next)
    printf("data = %d\n", ptr->data);
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
  maillon* current;
  maillon* previous;
  int i;
  l = (maillon*)malloc(sizeof(maillon));
  if(l == NULL)
    exit(0);
  l->data = 0;
  previous = l;
  for(i = 1 ; i < N ; i++)
    {
      current = (maillon*)malloc(sizeof(maillon));
      if(current == NULL)
	exit(0);
      current->data = i;
      previous->next = current;
      previous = current;
    }
  current->next = NULL;
  printData(l);
  freeLL(l);
  return 0;
}

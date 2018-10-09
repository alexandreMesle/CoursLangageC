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

void printData(maillon* ptr)
{
  for( ; ptr != NULL ; ptr = ptr->next)
    printf("data = %d\n", ptr->data);
}

/**************************************************************/

int main()
{
  maillon* l;
  int i;
  l = (maillon*)malloc(N * sizeof(maillon));
  if (l == NULL)
    return -1;
  l->data = 0;
  for(i = 1 ; i < N ; i++)
    {
      (l + i)->data = i;
      (l + i - 1)->next = l + i;
    }
  (l + N - 1)->next = NULL;
  printData(l);
  free(l);
  return 0;
}

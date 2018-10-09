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
    {
      printf("Plus de mémoire");
      return 1;  
    }
  l->data = 0;
  l->next = NULL;
  for(i = 1 ; i < N ; i++)
    {
      (l + i)->data = i;
      (l + i)->next = l + i - 1;
    }
  printData(l + N - 1);
  free(l);
  return 0;
}

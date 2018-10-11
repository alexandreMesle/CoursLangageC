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
  (l + 1)->data = 1;
  (l + N - 2)->next = l + 1;
  (l + N - 1)->next = NULL;
  for(i = 2 ; i < N ; i+=1)
    {
      (l + i)->data = i;
      (l + i - 2)->next = l + i;
    }
  printData(l);
  free(l);
  return 0;
}

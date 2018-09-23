#include<stdio.h>

/**************************************************************/

typedef struct maillon
{
        int data;
        struct maillon* next;
}maillon;

/**************************************************************/

int main()
{
  maillon m, p;
  maillon* ptr;
  m.data = 1;
  m.next = &p;
  p.data = 2;
  p.next = NULL;
  for (ptr = &m ; ptr != NULL ; ptr = ptr->next)
    printf("data = %d\n", ptr->data);
  return 0;
}

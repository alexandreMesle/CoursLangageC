#include<stdio.h>
#include<stdlib.h>

typedef struct maillon
{
  int data;
  struct maillon* next;
}maillon;

void ll_affiche(maillon* p)
{
  if(p != NULL)
    {
      printf("%d -> ", p->data);
      ll_affiche(p->next);
    }
  else
    printf("\n");
}

maillon* ll_cree(int n)
{
  maillon* p;
  if(n < 0)
    return NULL;
  p = (maillon*)malloc(sizeof(maillon));
  if (p == NULL)
    {
      printf("Plus de mémoire\n");
      return NULL;
    }
  p->data = n;
  p->next = ll_cree(n - 1);
  return p;
}

void ll_free(maillon* p)
{
  if (p != NULL)
    {
      ll_free(p->next);
      free(p);
    }
}

int main()
{
  maillon* p = ll_cree(10);
  if (p == NULL)
    return -1;
  ll_affiche(p);
  ll_free(p);
  return 0;
}

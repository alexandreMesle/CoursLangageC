#include<stdio.h>
#include<stdlib.h>

typedef struct maillon
{
  int data;
  struct maillon* next;
}maillon_t;

maillon_t* maillon_cree(int data, maillon_t* next)
{
  maillon_t* maillon = (maillon_t*)malloc(sizeof(maillon_t));
  maillon->data = data;
  maillon->next = next;
  return maillon;
}

void maillon_libere(maillon_t* liste)
{
  if (liste != NULL)
    {
      maillon_libere(liste->next);
      free(liste);
    }
}

maillon_t* maillon_compte_a_rebours(int n)
{
  if (n < 0)
    return NULL;
  return maillon_cree(n, maillon_compte_a_rebours(n - 1));
}

maillon_t* maillon_insere(maillon_t* liste, int valeur, int position)
{
  if(liste == NULL && position != 0)
    return NULL;
  if (position == 0)
    return maillon_cree(valeur, liste);
  liste->next = maillon_insere(liste->next, valeur, position - 1);
  return liste;    
}

void maillon_affiche(maillon_t* liste)
{
  if (liste != NULL)
  {
    printf("%d -> ", liste->data);
    maillon_affiche(liste->next);
  }
  else
    printf("\n");
}

int main()
{
  maillon_t* liste = maillon_compte_a_rebours(10);
  liste = maillon_insere(liste, 93, 3);
  maillon_affiche(liste);
  maillon_libere(liste);
  return 0;
}

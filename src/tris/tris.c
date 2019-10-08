#define N 100000
#define MODULE 1000

#include <stdio.h>
#include <stdlib.h>

typedef struct maillon_t
{
  int valeur;
  struct maillon_t* suivant;
}maillon_t;

maillon_t* maillon_cree(int valeur, maillon_t* suivant)
{
  maillon_t* maillon = (maillon_t*)malloc(sizeof(maillon_t));
  if (maillon == NULL)
    {
      printf("ACHTUNG !!!! Plus de mémoire");
      exit(1);
    }
  maillon->valeur = valeur;
  maillon->suivant = suivant;
  return maillon;
}

void maillon_libere(maillon_t* maillon)
{
  if (maillon != NULL)
    {
      maillon_libere(maillon->suivant);
      free(maillon);
    }
}

void maillon_affiche(maillon_t* maillon)
{
  if (maillon != NULL)
    {
      printf("%d -> ", maillon->valeur);
      maillon_affiche(maillon->suivant);
    }
  else
    printf("\n");
}

maillon_t* maillon_aleatoire(int nb_maillons)
{
  if (nb_maillons <= 0)
    return NULL;
  return maillon_cree(rand() % MODULE, maillon_aleatoire(nb_maillons - 1));
}

maillon_t* maillon_insere(maillon_t* liste_triee, maillon_t* element)
{
  if (liste_triee == NULL)
    {
      element->suivant = NULL;
      return element;
    }
  if (element->valeur < liste_triee->valeur)
    {
      element->suivant = liste_triee;
      return element;
    }
  liste_triee->suivant = maillon_insere(liste_triee->suivant, element);
  return liste_triee;
}

maillon_t* maillon_trie(maillon_t* maillon)
{
  if (maillon == NULL)
    return NULL;
  return maillon_insere(maillon_trie(maillon->suivant), maillon);
}

void maillon_separe(maillon_t* liste, maillon_t** liste_1, maillon_t** liste_2)
{
  if (liste != NULL)
    {
      maillon_separe(liste->suivant, liste_2, liste_1);
      liste->suivant = *liste_1;
      *liste_1 = liste;
    }
  else
    {
      *liste_1 = NULL;
      *liste_2 = NULL;
    }
}

maillon_t* maillon_interclasse(maillon_t* liste_1, maillon_t* liste_2)
{
  if (liste_1 == NULL)
    return liste_2;
  if (liste_2 == NULL)
    return liste_1;
  if (liste_1->valeur <= liste_2->valeur)
    {
      liste_1->suivant = maillon_interclasse(liste_1->suivant, liste_2);
      return liste_1;
    }
  else
    return maillon_interclasse(liste_2, liste_1);
}

maillon_t* tri_fusion(maillon_t* liste)
{
  if (liste == NULL || liste->suivant == NULL)
    return liste;
  maillon_t *liste_1, *liste_2;
  maillon_separe(liste, &liste_1, &liste_2);
  liste_1 = tri_fusion(liste_1);
  liste_2 = tri_fusion(liste_2);
  return maillon_interclasse(liste_1, liste_2);
}

int main()
{ 
  maillon_t* liste = maillon_aleatoire(N);
  printf("début du tri fusion\n");
  liste = tri_fusion(liste);
  printf("fin du tri fusion\n");
  maillon_libere(liste);
  liste = maillon_aleatoire(N);
  printf("début du tri insertion\n");
  liste = maillon_trie(liste);
  printf("fin du tri insertion\n");
  maillon_libere(liste);
  return 0;
}

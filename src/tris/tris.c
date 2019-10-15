#define N 100000
#define MODULE 1000

#include <stdio.h>
#include <stdlib.h>

typedef struct noeud
{
  int valeur;
  struct noeud *gauche, *droite;
}noeud_t;

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

noeud_t* noeud_cree(int valeur, noeud_t* gauche, noeud_t* droite)
{
  noeud_t* noeud = (noeud_t*)malloc(sizeof(noeud_t));
  if (noeud == NULL)
    {
      printf("Plus de Mémoire !!!!!!!!");
      exit(-1);
    }
  noeud->valeur = valeur;
  noeud->gauche = gauche;
  noeud->droite = droite;
  return noeud;
}

void noeud_libere(noeud_t* noeud)
{
  if (noeud == NULL)
    {
      noeud_libere(noeud->gauche);
      noeud_libere(noeud->droite);
      free(noeud);
    }
}

int noeud_contient(noeud_t* noeud, int valeur)
{
  if (noeud == NULL)
    return 0;
  if (noeud->valeur == valeur)
    return 1;
  if (valeur < noeud->valeur)
    return noeud_contient(noeud->gauche, valeur);
  return noeud_contient(noeud->droite, valeur);
}

noeud_t* noeud_insere(noeud_t* noeud, int valeur)
{
  if (noeud == NULL)
    return noeud_cree(valeur, NULL, NULL);
  if (valeur < noeud->valeur)
    noeud->gauche = noeud_insere(noeud->gauche, valeur);
  else
    noeud->droite = noeud_insere(noeud->droite, valeur);
  return noeud;    
}

noeud_t* noeud_compte_a_rebours(int n)
{
  if (n >= 0)
    return noeud_cree(n, noeud_compte_a_rebours(n-1), noeud_compte_a_rebours(n-1));
  else
    return NULL;
}

void noeud_affiche(noeud_t* noeud)
{
  if (noeud != NULL)
    {
      printf("(");
      noeud_affiche(noeud->gauche);
      printf(" %d ", noeud->valeur);
      noeud_affiche(noeud->droite);
      printf(")");
    }
}

noeud_t* noeud_aleatoire(int taille)
{
  if (taille == 0)
    return NULL;
  return noeud_insere(noeud_aleatoire(taille - 1), rand()%MODULE);
}

int main()
{ 
  /*
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
  */
  noeud_t* noeud = noeud_aleatoire(10);
  noeud_affiche(noeud);
  printf("\n");
  noeud_libere(noeud);
  return 0;
}

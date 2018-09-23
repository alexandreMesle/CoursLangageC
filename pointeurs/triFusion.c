#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MOD 10000

/*********************************************/

/*
  Affiche les n elements du tableau t.
*/

void printTab(int* t, int n)
{
  if (n > 0)
    {
      printf("%d ", *t);
      printTab(t + 1, n - 1);
    }
  else
    printf("\n");
}

/*********************************************/

/*
  Place n elements aleatoires de valeurs maximales
  MOD - 1 dans le tableau t.
*/

void initTab(int* t, int n)
{
  if (n > 0)
    {
      *t = rand()%MOD;
      initTab(t + 1, n - 1);
    }
}

/*********************************************/

/*
  Retourne un tableau de n 
  elements alloue dynamiquement.
*/

int* createTab(int n)
{
  int* t = (int*)malloc(sizeof(int)*n);
  if (t == NULL)
    {
      printf("no memory avalaible\n");
      exit(0);
    }
  return t;
}

/*********************************************/

/*
  Libere la zone memoire pointee par *t 
  et met ce pointeur a NULL.
*/

void destroyTab(int** t)
{
  free(*t);
  *t = NULL;
}

/*********************************************/

/*
  (recursive) 
  Retourne l'indice du plus petit
  element du tableau t a n elements. 
  Affiche une erreur si le tableau est vide.
*/

int indexOfMin(int* t, int n)
{
  if (n == 1)
      return 0;
  if (n > 1)
    {
      int rec = indexOfMin(t + 1, n - 1) + 1;
      return (*t < *(t + rec)) ? 0 : rec;
    }
  printf("Erreur dans la fonction indice du Min\n");
  return -1;
}

/*********************************************/

/*
  Echange les elements *x et *y.
*/

void swap(int* x, int* y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

/*********************************************/

/*
  Echange le plus petit element du tableau 
  t a n elements avec le premier.
*/

void swapMin(int* t, int n)
{
  swap(t, t + indexOfMin(t, n));
}

/*********************************************/

/*
  (recursive)
  Tri le tableau t a n elements avec la 
  methode du tri par selection.
*/

void selectionSort(int* t, int n)
{
  if (n > 0)
    {
      swapMin(t, n);
      selectionSort(t + 1, n - 1);
    }
}

/*********************************************/

/*
  (Recursive)
  Recopie les n elements du tableau source 
  a l'adresse dest.
 */

void copyTab(int* source, int* dest, int n)
{
  if(n > 0)
    {
      *dest = *source;
      copyTab(source + 1, dest + 1, n - 1);
    }
}

/*********************************************/

/*
  (Recursive)
  Interclasse les n1 elements de source1 avec les n2 elements de source2.
  source1 et source2 sont supposes tries. L'interclassement se fait 
  en disposant ces elements dans l'ordre dans le tableau dest.
*/

void shuffleTab(int* source1, int* source2, int* dest, 
		int n1, int n2)
{
  if (n1 > 0 || n2 > 0)
    {
      if (n1 == 0 || (n2 > 0 && *source2 < *source1))
	{
	  *dest = *source2;
	  shuffleTab(source1, source2 + 1, dest + 1, n1, n2 - 1);
	}
      else
	{
	  *dest = *source1;
	  shuffleTab(source1 + 1, source2, dest + 1, n1 - 1, n2);
	}
    }
}

/*********************************************/

/*
  Trie les n elements de t avec la methode du tri fusion.
*/

void fusionSort(int* t, int n)
{
  if (n > 1)
    {
      int m = n/2, *q, *r;
      q = createTab(m); 
      r = t + m;
      copyTab(t, q, m);
      fusionSort(q, m);
      fusionSort(r, n - m);
      shuffleTab(q, r, t, m, n - m);
      destroyTab(&q);
    }
}

/*********************************************/
 
/*
  Compare les performances en temps de calcul 
  des tris par selection et par fusion.
*/

int compareSorts(int firstValue, int lastValue, int step)
{
  int i;
  int start, stop;
  int *t, *q;
  srand(time(NULL));
  for(i = firstValue ; i <= lastValue ; i += step)
    {
      printf("with %d elements : \n", i);
      t = createTab(i);
      q = createTab(i);
      initTab(t, i);
      copyTab(t, q, i);
      start = time(NULL);
      selectionSort(t, i);
      stop = time(NULL);
      printf("* selection sort : %d\n", stop - start);
      destroyTab(&t);
      start = time(NULL);
      fusionSort(q, i);
      stop = time(NULL);
      printf("* fusion sort : %d\n", stop - start);
      destroyTab(&q);
    }
  return 0;
}

/*********************************************/
 
/*
  Pour tester les fonctions au fur et a mesure qu'elles sont 
  ecrites...
*/

int main()
{
  compareSorts(10000, 500000, 1000);
  return 0;
}

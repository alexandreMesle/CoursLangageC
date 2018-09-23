#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int getIntVal(int* p)
{
  return *p;
}

void setIntVal(int* p, int val)
{
  *p = val;
}

int* getTiAdr(int* t, int i)
{
  return t + i;
}

int getTiVal(int* t, int i)
{
  return getIntVal(getTiAdr(t, i));
}

void setTiVal(int* t, int i, int val)
{
  setIntVal(getTiAdr(t, i), val);
}

void swapInt(int* a, int* b)
{
  int temp;
  setIntVal(&temp, getIntVal(a));
  setIntVal(a, getIntVal(b));
  setIntVal(b, temp);
}

void swapTij(int* t, int i, int j)
{
  swapInt(getTiAdr(t, i), getTiAdr(t, j));
}

int** getTi_Adr(int** T, int i)
{
  return (T + i);
}

int* getTi_(int** T, int i)
{
  return *getTi_Adr(T, i);
}

void setT__Adr(int** t, int* p)
{
  *t = p;
}

void setTi_(int** t, int i, int* p)
{
  setT__Adr(getTi_Adr(t, i), p);
}

void createT__(int** T, int n, int m)
{
  int i;
  for(i = 0 ; i < n ; i++)
    {
      setTi_(T, i, (int *)malloc(m * sizeof(int)));
      if (getTi_(T, i) == NULL)
	{
	  printf("Heap overflow\n");
	  exit(-1);
	}
    }
}

int* getTijAdr(int** t, int i, int j)
{
  return getTiAdr(getTi_(t, i), j);
}

int getTijVal(int** t, int i, int j)
{
  return getIntVal(getTijAdr(t, i, j));
}

void setTijVal(int** t, int i, int j, int val)
{
  setTiVal(getTi_(t, i), j, val);
  // ou bien setIntAdr(getTijAdr(t, i, j), val)
}

int C_j_i(int** t, int i, int j)
{
  if (j == 0 || i == j)
    return 1;
  return getTijVal(t, i-1, j-1) + getTijVal(t, i-1, j);
}

void mallocPascal(int** p, int n)
{
  int i;
  for(i = 0 ; i <= n ; i++)
    {
      setTi_(p, i, (int *)malloc((i + 1) * sizeof(int)));
      if (getTi_(p, i) == NULL)
	{
	  printf("Heap overflow\n");
	  exit(-1);
	}
    }
}

void setC_j_i(int** t, int n)
{
  int i, j;
  for (i = 0 ; i <= n ; i++)
    for (j = 0 ; j <= i; j++)
      setTijVal(t, i, j, C_j_i(t, i, j));
}

int** pascal(int n)
{
  int** p;
  p = (int**)malloc(n * sizeof(int*));
  if (p == NULL)
    {
      printf("Heap overflow\n");
      exit(-1);
    }
  mallocPascal(p, n);
  setC_j_i(p, n);
  return p;
}

void printPascal(int** p, int n)
{
  int i, j;
  for (i = 0 ; i <= n ; i++)
    {
      for (j = 0 ; j <= i ; j++)
	printf("%d ", getTijVal(p, i, j));
      printf("\n");
    }
}

void freePascal(int** p, int n)
{
  int i;
  for(i = 0 ; i <= n ; i++)
    {
      free(getTi_(p, i));
    }
  free(p);
}

main()
{
  int** p = pascal(15);
  printPascal(p, 15);
}

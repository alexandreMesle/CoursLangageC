#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define N 10

/**************************************************************/

typedef struct point
{
  double abs;
  double ord;
}point;

/**************************************************************/

point nextPoint(point* previous)
{
  point result;
  result.ord = (*previous).ord + 1.;
  result.abs = (*previous).abs + 2.;
  return result;
}

/**************************************************************/

void initTableauPoints(point* p, int n)
{
  int i;
  (*p).ord = 0;
  (*p).abs = 1;
  for(i = 1 ; i < n ; i++)
    *(p + i) = nextPoint(p + i - 1);
}

/**************************************************************/

void affichePoint(point* p)
{
  printf("(%f, %f)", (*p).abs, (*p).ord);
}

/**************************************************************/

void afficheTableauPoints(point* p, int n)
{
  int i;
 for(i = 1 ; i < n ; i++)
    {
      printf("p[%d] = ", i);
      affichePoint(p + i);
      printf("\n");
    }  
}

/**************************************************************/

int main()
{
  point* p;
  p = (point*)malloc(N * sizeof(point));
  if (p == NULL)
    exit(0);
  initTableauPoints(p, N);
  afficheTableauPoints(p, N);  
  free(p);
  return 0;
}

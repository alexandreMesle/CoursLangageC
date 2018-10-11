#include<stdio.h>

#define N 10

typedef struct point
{
  double abs;
  double ord;
}point;

point nextPoint(point previous)
{
  point result;
  result.ord = previous.ord + 1.;
  result.abs = previous.abs + 2.;
  return result;
}

void initTableauPoints(point p[], int n)
{
  int i;
  p[0].ord = 0;
  p[0].abs = 1;
  for(i = 1 ; i < n ; i++)
    p[i] = nextPoint(p[i - 1]);
}

void affichePoint(point p)
{
  printf("(%f, %f)", p.abs, p.ord);
}

void afficheTableauPoints(point p[], int n)
{
  int i;
 for(i = 0 ; i < n ; i++)
    {
      printf("p[%d] = ", i);
      affichePoint(p[i]);
      printf("\n");
    }  
}

main()
{
  point p[N];
  initTableauPoints(p, N);
  afficheTableauPoints(p, N);  
}

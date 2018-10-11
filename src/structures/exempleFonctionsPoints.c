#include<stdio.h>

#define N 10

typedef struct point
{
  double abs;
  double ord;
}point;

void initTableauPoints(point p[], int n)
{
  int i;
  p[0].ord = 0;
  p[0].abs = 1;
  for(i = 1 ; i < n ; i++)
    {
      p[i].ord = p[i - 1].ord + 1.;
      p[i].abs = p[i - 1].abs + 2.;
    }  
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

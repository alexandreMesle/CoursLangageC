#include<stdio.h>

#define N 10

typedef struct point
{
  double abs;
  double ord;
}point;


main()
{
  point p[N];
  int i;
  p[0].ord = 0;
  p[0].abs = 1;
  for(i = 1 ; i < N ; i++)
    {
      p[i].ord = p[i - 1].ord + 1.;
      p[i].abs = p[i - 1].abs + 2.;
    }
  for(i = 0 ; i < N ; i++)
    {
      printf("p[%d] = (%f, %f)\n", i, p[i].abs, p[i].ord);
    }  
}

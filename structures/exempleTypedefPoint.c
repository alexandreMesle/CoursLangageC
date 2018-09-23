#include<stdio.h>

typedef struct point
{
  double abs;
  double ord;
}point;


main()
{
  point p;
  p.ord = 2;
  p.abs = p.ord + 1;
  printf("p = (%f, %f)\n", p.abs, p.ord);
}

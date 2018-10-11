#include<stdio.h>

struct point
{
  double abs;
  double ord;
};


main()
{
  struct point p;
  p.ord = 2;
  p.abs = p.ord + 1;
  printf("p = (%f, %f)\n", p.abs, p.ord);
}

#include<stdio.h>

main()
{
  int i = 4;
  int j = 10;
  int* p;
  int* q;
  p = &i;
  q = &j;
  printf("i = %d, j = %d, p = %d, q = %d\n", i, j, *p, *q);
  *p = *p + *q;
  printf("i = %d, j = %d, p = %d, q = %d\n", i, j, *p, *q);
  p = &j;
  printf("i = %d, j = %d, p = %d, q = %d\n", i, j, *p, *q);
  *q = *q + *p;
  printf("i = %d, j = %d, p = %d, q = %d\n", i, j, *p, *q);
  q = &i;
  printf("i = %d, j = %d, p = %d, q = %d\n", i, j, *p, *q);
  i = 4;
  printf("i = %d, j = %d, p = %d, q = %d\n", i, j, *p, *q);
  *q = *q + 1;
  printf("i = %d, j = %d, p = %d, q = %d\n", i, j, *p, *q);
}

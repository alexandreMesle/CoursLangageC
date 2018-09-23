#include<stdio.h>
#include<malloc.h>

main()
{
  int* p;
  p = (int*)malloc(2);
  *p = 28;
  printf("%d\n", *p);
  free(p);
}

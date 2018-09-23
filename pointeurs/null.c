#include<stdio.h>
#include<malloc.h>

main()
{
  int* p;
  p = (int*)malloc(2);
  if(p == NULL)
    exit(0);
  *p = 28;
  printf("%d\n", *p);
  free(p);
}

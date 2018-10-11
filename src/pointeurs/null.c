#include<stdio.h>
#include<stdlib.h>

int main()
{
  int* p;
  p = (int*)malloc(sizeof(int));
  if(p == NULL)
    exit(0);
  *p = 28;
  printf("%d\n", *p);
  free(p);
  return 0;
}

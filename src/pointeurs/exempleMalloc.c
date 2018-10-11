#include<stdio.h>
#include<stdlib.h>

int main()
{
  int* p;
  p = (int*)malloc(sizeof(int));
  *p = 28;
  printf("%d\n", *p);
  return 0;
}

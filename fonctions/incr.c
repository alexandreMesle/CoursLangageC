#include<stdio.h>

void incr(int v)
{
  v++;
}

main()
{
  int i;
  i = 6;
  incr(i);
  printf("%d\n", i);
}

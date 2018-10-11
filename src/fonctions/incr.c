#include<stdio.h>

void incr(int v)
{
  v++;
}

int main()
{
  int i;
  i = 6;
  incr(i);
  printf("%d\n", i);
  return 0;
}

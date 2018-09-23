#include<stdio.h>

int main()
{
  int i = 4, j = 1, k = 3, l;
  printf("i = %d, j = %d, k = %d, l = %d\n", i, j, k, l);
  printf("%d\n", (i> (l = (j>k) ? j : k)) ? i : l); 
  printf("i = %d, j = %d, k = %d, l = %d\n", i, j, k, l);
  return 0;
}

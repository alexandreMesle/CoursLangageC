#include<stdio.h>

#define N 500

int main()
{
  char c[N] = "Les framboises sont perchees sur le "
    "tabouret de mon grand-pere.";
  int i = 0;
  while(c[i] != 0)
    printf("%c", c[i++]);
  printf("\n");
  return 0;
}

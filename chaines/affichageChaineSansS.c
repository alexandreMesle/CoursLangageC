#include<stdio.h>

int main()
{
  char s[64] = "Les framboises sont perchees "
    "sur le tabouret de mon grand-pere.";
  int i = 0;
  while(s[i] != 0)
    printf("%c", s[i++]);
  printf("\n");
  return 0;
}

#include<stdio.h>

#define BUFFER_SIZE 150
#define CLEAR_BUFFER while(getchar() != '\n')

int main()
{
  char s[BUFFER_SIZE];
  int i = 0;
  fgets(s, BUFFER_SIZE, stdin);
  while(s[i] != 0)
    i++;
  if (s[i - 1] != '\n')
    CLEAR_BUFFER;
  printf("longueur = %d\n", i);
  return 0;
}

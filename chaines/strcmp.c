#include<stdio.h>
#include<string.h>

#define BUFFER_SIZE 30
#define CLEAR_BUFFER while(getchar() != '\n')

int main()
{
  char s[BUFFER_SIZE], t[BUFFER_SIZE];
  int r;
  printf("Saisir une chaîne : \n");
  fgets(s, BUFFER_SIZE, stdin);
  if (s[strlen(s) - 1] != '\n')
    CLEAR_BUFFER;
  else
    s[strlen(s) - 1] = 0;
  printf("Saisir une autre chaîne : \n");
  fgets(t, BUFFER_SIZE, stdin);
  if (t[strlen(t) - 1] != '\n')
    CLEAR_BUFFER;
  t[strlen(t) - 1] = 0;
  printf("%s ", s);
  r = strcmp(s, t);
  if (r == 0)
    printf("=");
  else if (r < 0)
    printf("<");
  else
    printf(">");
  printf(" %s\n", t);
  return 0;
}

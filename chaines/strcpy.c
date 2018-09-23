#include<stdio.h>
#include<string.h>

#define BUFFER_SIZE 30
#define CLEAR_BUFFER while(getchar() != '\n')

int main()
{
  char s[BUFFER_SIZE], t[BUFFER_SIZE];
  printf("Saisir une chaîne : \n");
  fgets(s, BUFFER_SIZE, stdin);
  if (s[strlen(s) - 1] != '\n')
    CLEAR_BUFFER;
  else
    s[strlen(s) - 1] = 0;
  strcpy(t, s);
  printf("%s est copie dans %s\n", s, t);
  return 0;
}

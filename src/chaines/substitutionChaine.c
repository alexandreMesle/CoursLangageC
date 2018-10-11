#include<stdio.h>
#include<string.h>

#define BUFFER_SIZE 30
#define CLEAR_BUFFER while(getchar() != '\n')

int main()
{
  char s[BUFFER_SIZE], a, b;
  int k;
  printf("Saisir une chaîne : \n");
  fgets(s, BUFFER_SIZE, stdin);
  if (s[strlen(s) - 1] != '\n')
    CLEAR_BUFFER;
  else
      s[strlen(s) - 1] = 0;
  printf("Saisir le caractère a rechercher : ");
  scanf("%c", &a);
  getchar();
  printf("Saisir le caractère a substituer : ");
  scanf("%c", &b);
  k = 0;
  while(s[k] != 0)
    {
    if (s[k] == a)
      s[k] = b;
    k++;
    }
  printf("%s\n", s);
  return 0;
}

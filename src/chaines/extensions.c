#include<stdio.h>
#include<string.h>

#define BUFFER_SIZE 100
#define CLEAR_BUFFER while(getchar() != '\n')

int main()
{
  char s[BUFFER_SIZE];
  int k, i;
  printf("Saisir une chaîne : \n");
  fgets(s, BUFFER_SIZE, stdin);
  if (s[strlen(s) - 1] != '\n')
    CLEAR_BUFFER;
  else
    s[strlen(s) - 1] = 0;
  i = 1;
  k = 0;
  printf("nom du fichier : ");
  while(s[k] != 0)
    {
      if (s[k] == '.')
	printf("\n%d-eme extension : ", i++);
      else
	printf("%c", s[k]);
      k++;
    }
  printf("\n");
  return 0;
}

#include<stdio.h>
#include<string.h>

#define BUFFER_SIZE 30
#define CLEAR_BUFFER while(getchar() != '\n')

int main()
{
  char s[BUFFER_SIZE];
  int k, i;
  printf("Saisir une chaine : \n");
  fgets(s, BUFFER_SIZE, stdin);
  if (s[strlen(s) - 1] != '\n')
    CLEAR_BUFFER;
  else
    s[strlen(s) - 1] = 0;
  k = 0;
  i = 0;
  while(s[k] != 0)
    {
      if (s[k] == '(')
	i++;
      if (s[k] == ')')
	i--;
      if (i < 0)
	{
	  printf("Expression mal parenthesee !\n");
	  return -1;
	}
      k++;
    }
  if (i != 0)
    {
      printf("Expression mal parenthesee !\n");
      return -1;
    }
  printf("L'expression est correctement parenthesee !\n");
  return 0;
}

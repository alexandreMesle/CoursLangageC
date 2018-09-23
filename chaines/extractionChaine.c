#include<stdio.h>
#include<string.h>

#define BUFFER_SIZE 30
#define CLEAR_BUFFER while(getchar() != '\n')

int main()
{
  char s[BUFFER_SIZE], copie[BUFFER_SIZE];
  int k = 0, i, j;
  printf("Saisir une chaîne : \n");
  fgets(s, BUFFER_SIZE, stdin);
  if (s[strlen(s) - 1] != '\n')
    CLEAR_BUFFER;
  printf("Saisir l'indice de debut : ");
  scanf("%d", &i);
  printf("Saisir l'indice de fin : ");
  scanf("%d", &j);
  if (i < 0 || j > strlen(s) || i > j)
    {
      printf("Erreur de saisie !");
      return 1;
    }
  else
    {
      while(i <= j)
	{
	  copie[k] = s[i];
	  i++; 
	  k++;
	}
      copie[k] = 0;
    }
  printf("%s\n", copie);
  return 0;
}

#include<stdio.h>
#include<stdlib.h>

#define B_SIZE 10
#define CLEAR_BUFFER while(getchar() != '\n')

int main()
{
  char buffer[B_SIZE], *copie;
  int len = 0, i;
  printf("Saisissez une chaine de caractère : \n");
  fgets(buffer, B_SIZE, stdin);
  while(buffer[len] != 0)
    len ++;
  if (buffer[len - 1] != '\n')
    CLEAR_BUFFER;
  else
    len--;
  copie = (char*)malloc(sizeof(char) * (len + 1));
  for(i = 0 ; i < len ; i++)
    *(copie + i) = buffer[i];
  *(copie + len) = 0;
  i = 0;
  while(*(copie + i) != 0)
    printf("%c", *(copie + i++));
  printf("\n");
  free(copie);
  return 0;
}

#include<stdio.h>
#include<stdlib.h>

#define B_SIZE 10
#define NB_S 4
#define CLEAR_BUFFER while(getchar() != '\n')

int main()
{
  char buffer[B_SIZE], **copies;
  int len = 0, j, i;
  copies = (char**)malloc(NB_S * sizeof(char*));
  for(j = 0 ; j < NB_S ; j++)
    {
      printf("Saisissez une chaine de caractère : \n");
      fgets(buffer, B_SIZE, stdin);
      while(buffer[len] != 0)
	len ++;
      if (buffer[len - 1] != '\n')
	CLEAR_BUFFER;
      else
	len--;
      *(copies + j) = (char*)malloc(sizeof(char) * (len + 1));
      for(i = 0 ; i < len ; i++)
	*(*(copies + j) + i) = buffer[i];
      *(*(copies + j) + len) = 0;
    }
  for(j = 0 ; j < NB_S ; j++)
    {
      i = 0;
      while(*(*(copies + j) + i) != 0)
	printf("%c", *(*(copies + j) + i++));
      printf("\n");
      free(*(copies + j));
    }
  free(copies);
  return 0;
}

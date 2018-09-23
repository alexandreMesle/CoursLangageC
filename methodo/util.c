#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getString(char* adr,  int sizeMax)
{
  int len;
  fgets(adr, sizeMax, stdin);
  len = strlen(adr);
  if (*(adr + len - 1) == '\n')
      *(adr + len - 1) = 0;
  else
    while(getchar() != '\n');
}

/*****************************************************/

int getInt()
{
  char tab[10];
  getString(tab, 10);
  return atoi(tab);
}

/**********************************************************/

void swapStrings(char* s1, char* s2, int sizeMax)
{
  char temp[sizeMax];
  strncpy(temp, s1, sizeMax);
  strncpy(s1, s2, sizeMax);
  strncpy(s2, temp, sizeMax);  
  *(s1 + sizeMax - 1) = 0;
  *(s2 + sizeMax - 1) = 0;
}


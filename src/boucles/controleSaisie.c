#include<stdio.h>

int main()
{
  int i;
  do
    {
      printf("Saisissez un entier positif ou nul : ");
      scanf("%d", &i);
      if (i < 0)
	printf("J'ai dit positif ou nul ! `\n");
    }
  while(i < 0);
  return 0;
}

#include<stdio.h>

main()
{
  int T[10];
  int I[10];
  int n = 0;
  int i;
  int k = 6;
  for(i = 0 ; i < 10 ; i++)
    T[i] = i*i % 10; 
  for(i = 0 ; i < 10 ; i++)
    {
      if (T[i] == k)
	{
	  I[n] = i;
	  n++;
	}
    }
  if (n)
    {
      printf("L'element a trouve aux positions ");
      for(i = 0 ; i < n ; i++)
	printf("%d ", I[i]);
      printf("\n");
    }
  else
    printf("L'element n' a pas ete trouve.");
}

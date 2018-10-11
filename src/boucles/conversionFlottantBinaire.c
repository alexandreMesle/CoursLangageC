#include<stdio.h>
#include<string.h>

int main()
{
  float d = 12.5;
  unsigned short size = sizeof(float), i, j, k;
  unsigned char oct[size], mask;
  /*printf("Saisissez une valeur entre 0 et 1: ");
    scanf("%lf", &d);*/
  for (j = 1 ; j <= 20 ; j++)
    {
      memcpy(oct, &d, size);
      printf("%10.2f = ", d);
      for(i = 0 ; i < size ; i++)
	{
	  mask = 1<<7;
	  for(k = 1 ; k <= 8 ; k++)
	    {
	      printf("%hu", (oct[i]&mask)!=0);
	      mask>>=1;
	    }
	  printf(".");
	}
      printf("\n");
     d *= 2;
    }
  return 0;
}

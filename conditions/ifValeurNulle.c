#include<stdio.h>

int main()
{
	int i;
	printf("Saisissez une valeur : ");
	scanf("%d", &i);
	if (i == 0)
	{
		printf("Vous avez saisi une valeur nulle\n.");
	}
	printf("Adios !");
	return 0;
}

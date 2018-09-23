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
	else
	{
		printf("La valeur que vous saisi, "
                "a savoir %d, n'est pas nulle.\n", i);
	}
	return 0;
}

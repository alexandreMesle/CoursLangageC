#include<stdio.h>

int main(int argv, char** argc)
{
	FILE* f;
	int c;
	if (argv == 1)
		f = fopen("toto", "r");
	else
		f = fopen(*(argc + 1), "r");
	if (f == NULL)
		return 1;
	c = getc(f);
	while (c != EOF)
	{
		printf("%c", c);
		c = getc(f);
	}
	printf("\n");
	fclose(f);
	return 0;
}

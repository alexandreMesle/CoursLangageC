#include<stdio.h>

int main(int argv, char** argc)
{
	FILE* source;
	FILE* dest;
	int c;
	source = fopen(*(argc + 1), "r");
	dest = fopen(*(argc + 2), "w");
	if (source == NULL || dest == NULL)
		return 1;
	while ((c  = getc(source))!= EOF)
	{
		fputc(c, dest);
	}
	fclose(source);
	fclose(dest);
	return 0;
}

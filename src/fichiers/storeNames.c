#include<string.h>
#include<stdio.h>

int main(int argv, char** argc)
{
	FILE* f;
	char buffer[250];
	f = fopen(*(argc + 1), "w");
	if (f == NULL)
		return 1;
	fgets(buffer, 250, stdin);
	while(strcmp("-1", buffer))
	{
		fputs(buffer, f);
		fputc('\n', f);
		fgets(buffer, 250, stdin);
	}
	fclose(f);
	return 0;
}

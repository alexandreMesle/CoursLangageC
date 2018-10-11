#include<string.h>
#include<stdio.h>

int main(int argv, char** argc)
{
	FILE* f;
	char buffer[250];
	f = fopen(*(argc + 1), "r");
	if (f == NULL)
		return 1;
	while(fgets(buffer, 249, f))
	{
		printf("%s", buffer);
	}
	fclose(f);
	return 0;
}

#include<string.h>
#include<stdio.h>

struct personne
{
  char nom[30];
  int age;
};

int main(int argv, char** argc)
{
	FILE* f;
	int i, n = 0;
	struct personne repertoire[3];
	f = fopen("toto.txt", "r");
	if (f == NULL)
		return 1;
	while(fread(repertoire + n, 1, sizeof(struct personne), f))
	  n++;
	for (i = 0 ; i < n ; i++)
	  printf("%s %d\n", repertoire[i].nom, repertoire[i].age);
	fclose(f);
	return 0;
}

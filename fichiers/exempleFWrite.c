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
	struct personne repertoire[3] = 
	  {{"tata", 2}, {"toto", 8}, {"titi", -1}}; 
	f = fopen("toto.txt", "w");
	if (f == NULL)
		return 1;
	fwrite(repertoire, 3, sizeof(struct personne), f);
	fclose(f);
	return 0;
}

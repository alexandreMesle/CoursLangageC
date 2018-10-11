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
	struct personne repertoire[4] = 
	  {{"tata", 2}, {"toto", 8}, {"titi", -1}, {"tutu", 9}}; 
	f = fopen("toto.txt", "w");
	if (f == NULL)
	  {
	    printf("Impossible d'ouvrir le fichier toto.txt");
	    return -1;
	  }
	fwrite(repertoire, 4, sizeof(struct personne), f);
	if (fclose(f))
	  {
	    printf("Impossible de fermer le fichier toto.txt");
	    return -2;
	  }
	return 0;
}

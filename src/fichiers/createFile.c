#include<stdio.h>

int main(int argc, char* argv[])
{
  FILE* f;
  int i;
  if (argc < 2)
    {
      printf("Syntax : ./touch fname contents\n" \
	     "where : \n- fname is a string without "\
	     "space or special character\n" \
	     "- contents is a string without "\
	     "special character\n");
      return -1;      
    }
  f = fopen(*(argv + 1), "w");
  if (f == NULL)
    {
      printf("Erreur lors de l'ouverture du fichier %s\n", 
	     *(argv + 1));
      return -1;
    }
  for (i = 2 ; i < argc ; i++)
    {
      fputs(*(argv + i), f);
      if (i != argc - 1)
	fputc(' ', f);
    }
  if (fclose(f) != 0)
    {
      printf("Erreur lors de la fermeture du fichier %s\n", 
	     *(argv + 1));
      return -1;
    }
  return 0;
}

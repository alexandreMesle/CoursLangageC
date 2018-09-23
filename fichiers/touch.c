#include<stdio.h>

int main(int argc, char* argv[])
{
  FILE* f;
  if (argc != 2)
    {
      printf("Syntax : ./touch fname\nwhere fname is a string without "\
	     "space or special character\n");
      return -1;      
    }
  f = fopen(*(argv + 1), "w");
  if (f == NULL)
    {
      printf("Erreur lors de l'ouverture du fichier %s\n", 
	     *(argv + 1));
      return -1;
    }
  if (fclose(f) != 0)
    {
      printf("Erreur lors de la fermeture du fichier %s\n", 
	     *(argv + 1));
      return -1;
    }
  return 0;
}

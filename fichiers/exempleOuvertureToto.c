#include<stdio.h>

int main()
{
  FILE* f;
  f = fopen("toto.txt", "r");
  if (f == NULL)
    {
      printf("Erreur lors de l'ouverture du fichier toto.txt\n");
      return -1;
    }
  /*
    Lecture dans le fichier
    ...
   */
  if (fclose(f))
    {
      printf("Erreur lors de la fermeture du fichier toto.txt\n");
      return -1;
    }
  return 0;
}

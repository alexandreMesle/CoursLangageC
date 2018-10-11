#include<stdio.h>

int main()
{
  FILE* f;
  char c;
  f = fopen("toto.txt", "r");
  if (f == NULL)
    {
      printf("Erreur lors de l'ouverture du fichier toto.txt\n");
      return -1;
    }
  while((c = fgetc(f)) != EOF)
    printf("caractere lu : %c\n", c);
  if (fclose(f))
    {
      printf("Erreur lors de la fermeture du fichier toto.txt\n");
      return -1;
    }
  return 0;
}

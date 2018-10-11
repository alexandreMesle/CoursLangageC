#include<stdio.h>

int main()
{
  FILE* f;
  char c[8] = "Toto !\n";
  int i;
  f = fopen("toto.txt", "w");
  if (f == NULL)
    {
      printf("Erreur lors de l'ouverture du fichier toto.txt\n");
      return -1;
    }
  for(i = 0 ; i < 7 ; i++)
    fputc(c[i], f);
  if (fclose(f))
    {
      printf("Erreur lors de la fermeture du fichier toto.txt\n");
      return -2;
    }
  return 0;
}

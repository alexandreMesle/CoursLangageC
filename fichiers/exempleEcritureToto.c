#include<stdio.h>

int main()
{
  FILE* f;
  char c[7] = "Toto !";
  int i;
  f = fopen("toto.txt", "w");
  if (f == NULL)
    {
      printf("Erreur lors de l'ouverture du fichier toto.txt\n");
      return -1;
    }
  for(i = 0 ; i < 6 ; i++)
    fputc(c[i], f);
  if (fclose(f) != 0)
    {
      printf("Erreur lors de la fermeture du fichier toto.txt\n");
      return -1;
    }
  return 0;
}

#include<stdio.h>

void afficheBonjour()
{
  printf("Bonjour\n");
}

void afficheUn()
{
  printf("1\n");
}

void afficheDeux()
{
  printf("2\n");
}

void afficheUnEtDeux()
{
  afficheUn();
  afficheDeux();
}

void afficheAuRevoir()
{
  printf("Au revoir\n");
}

int main()
{
  afficheBonjour();
  afficheUnEtDeux();
  afficheAuRevoir();
  return 0;
}

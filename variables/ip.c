#include<stdio.h>

int main()
{
  unsigned long ip = 0, masque = 255;
  unsigned short octet1, octet2, octet3, octet4;
  printf("Saississez les quatre chiffres de l'adresse IP\n"
	 "Premiere valeur : ");
  scanf("%hu", &octet1);
  ip = octet1;
  ip <<= 8;
  printf("Deuxieme valeur : ");
  scanf("%hu", &octet2);
  ip |= octet2;
  ip <<= 8;
  printf("Troisieme valeur : ");
  scanf("%hu", &octet3);
  ip |= octet3;
  ip <<= 8;
  printf("Quatrieme valeur : ");
  scanf("%hu", &octet4);
  ip |= octet4;
  printf("Cette IP se code en long sous la forme %lu.\n", ip);
  printf("Vous remarquez qu'il est possible de la retrouver : ");
  octet4 = ip & masque;
  ip >>= 8;
  octet3 = ip & masque;
  ip >>= 8;
  octet2 = ip & masque;
  ip >>= 8;
  octet1 = ip & masque;
  printf("%hu.%hu.%hu.%hu\n", octet1, octet2, octet3, octet4);
  return 0;
}

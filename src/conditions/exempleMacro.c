#include<stdio.h>

#define BEGIN {
#define END }

#define RC printf("\n")
#define AFFICHE_DEBUT printf("Debut")
#define AFFICHE_FIN printf("Fin")
#define AFFICHE_MLILIEU printf("Milieu")
#define RETOURNE_0 return 0


int main()
BEGIN
  AFFICHE_DEBUT;
  RC;
  AFFICHE_MLILIEU; 
  RC;
  AFFICHE_FIN; 
  RC;
  RETOURNE_0;
END

#include<stdio.h>

#define AFFICHE_UNITE(i) \
if (i == 1) printf("un"); \
if (i == 2) printf("deux"); \
if (i == 3) printf("trois"); \
if (i == 4) printf("quatre"); \
if (i == 5) printf("cinq"); \
if (i == 6) printf("six"); \
if (i == 7) printf("sept"); \
if (i == 8) printf("huit"); \
if (i == 9) printf("neuf"); \
if (i == 10) printf("dix"); \
if (i == 11) printf("onze"); \
if (i == 12) printf("douze"); \
if (i == 13) printf("treize"); \
if (i == 14) printf("quatorze"); \
if (i == 15) printf("quinze"); \
if (i == 16) printf("seize"); \
if (i == 17) printf("dix-sept"); \
if (i == 18) printf("dix-huit"); \
if (i == 19) printf("dix-neuf")

#define AFFICHE_DIZAINE(i) \
if (i == 2) printf("vingt"); \
if (i == 3) printf("trente"); \
if (i == 4) printf("quarante"); \
if (i == 5) printf("cinquante"); \
if (i == 6) printf("soixante"); \
if (i == 7) printf("soixante"); \
if (i == 8) printf("quatre-vingt"); \
if (i == 9) printf("quatre-vingt")

#define AFFICHE_TROIS_CHIFFRES(nb) \
{ \
      unsigned long unites, dizaines, centaines, deuxDerniers;\
      unites = (nb) % 10;\
      dizaines = ((nb) - unites) / 10 % 10;\
      deuxDerniers = 10*dizaines + unites;\
      centaines = ((nb) - (nb)%100) / 100 % 10;\
      if (centaines >= 2)\
	{\
	  AFFICHE_UNITE(centaines);\
	  printf("-");\
	}\
      if (centaines > 0)\
	printf("cent");\
      if (deuxDerniers == 0 && centaines > 1 )\
	printf("s");\
      if (centaines > 0 && deuxDerniers != 0) \
	printf("-");\
      if(dizaines > 1)\
	{\
	  AFFICHE_DIZAINE(dizaines);  \
	}\
      if (dizaines == 8 && unites == 0)\
	printf("s");\
      if ((dizaines > 1 && unites != 0) \
	  || dizaines == 7 || dizaines == 9)\
	printf("-");\
      if (unites == 1 && \
	  dizaines < 7 && dizaines > 1)\
	printf("et-");		  \
      if(dizaines == 7)\
	{\
	  AFFICHE_UNITE(deuxDerniers - 60);  \
	}\
      else\
	if(dizaines == 9)\
	  {\
	    AFFICHE_UNITE(deuxDerniers - 80);  \
	  }\
	else\
	  if (dizaines == 1)\
	    {\
	      AFFICHE_UNITE(deuxDerniers);\
	    }\
	  else	      \
	    {\
	      AFFICHE_UNITE(unites);\
	    }\
}

#define AFFICHE_TROIS_CHIFFRES_UNITE(c, nom_unite, valeur_unite) \
{ \
  if (c%(valeur_unite*mille)/valeur_unite >= 2)\
    {\
      AFFICHE_TROIS_CHIFFRES(c/valeur_unite/*%mille*/); \
      printf(" ");\
      printf("%ss ", nom_unite);\
    }\
  if (c%(valeur_unite*mille) >= valeur_unite && c%(valeur_unite*mille) < 2*valeur_unite)\
    {\
      printf("un %s ", nom_unite);\
    }\
}

int main()
{
  unsigned long i = 2010000001, mille = 1000;
  printf("Saisissez un nombre = ");
  scanf("%lu", &i); 
  printf("%10lu : ", i);
  AFFICHE_TROIS_CHIFFRES_UNITE(i, "milliard", (unsigned long)1e9);
  AFFICHE_TROIS_CHIFFRES_UNITE(i, "million", (unsigned long)1e6);
  if (i%(mille*mille)/mille >= 2)
    {
      AFFICHE_TROIS_CHIFFRES(i/mille%mille);
      printf(" ");
      }
  if (i%(mille * mille) >= mille)
    printf("mille ");
  AFFICHE_TROIS_CHIFFRES(i%mille);
  if (i == 0)
    printf("zero");
  printf("\n");
  return 0;
}

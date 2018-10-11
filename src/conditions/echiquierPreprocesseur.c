#include<stdio.h>
#include<stdlib.h>

/*-----------------------------------------------*/

#define CAVALIER 0
#define TOUR 1
#define FOU 2
#define DAME 3
#define ROI 4

/*-----------------------------------------------*/

#define MAIN int main() \
		{

/*-----------------------------------------------*/

#define FINMAIN return 0;\
		}
/*-----------------------------------------------*/

#define SI if(

/*-----------------------------------------------*/

#define ALORS ){

/*-----------------------------------------------*/

#define SINON } else {

/*-----------------------------------------------*/

#define FINSI }

/*-----------------------------------------------*/

#define SUIVANT(var) switch(var) {

/*-----------------------------------------------*/

#define FINSUIVANT(def) default: def }

/*-----------------------------------------------*/

#define CAS(valeur, instructions) case valeur : instructions \
				break;

/*-----------------------------------------------*/

#define PIECES_LIST   \
printf("%hu = Cavalier\n", CAVALIER); \
printf("%hu = Tour\n", TOUR); \
printf("%hu = Fou\n", FOU); \
printf("%hu = Dame\n", DAME); \
printf("%hu = Roi\n", ROI)

/*-----------------------------------------------*/

#define CHECK_COORD(i) \
SI i<1 || i>8 ALORS \
	printf("coordonnee invalide\n"); \
	return 1; \
FINSI

/*-----------------------------------------------*/

#define GET_VAR(A, B) \
		printf("A = "); \
		scanf("%hu", &B); \
		CHECK_COORD(B);

/*-----------------------------------------------*/

#define PRINT_VALID printf("valide")

/*-----------------------------------------------*/

#define PRINT_INVALID printf("invalide")

/*-----------------------------------------------*/

#define FATAL_ERROR printf("System Error. It is recommended that " \
		"you format your hard disk."); \
		return 1;

/*-----------------------------------------------*/

#define CONDITIONAL_PRINT(cond) \
SI cond ALORS \
  PRINT_VALID; \
SINON \
  PRINT_INVALID; \
FINSI

/*-----------------------------------------------*/

MAIN
	unsigned short iD, jD, iA, jA, piece;
	printf("Quelle piece souhaitez-vous deplacer ?\n");
	PIECES_LIST;
  	scanf("%hu", &piece);
	printf("Saisissez les coordonnees de la case de depart : \n");
        GET_VAR(i, iD);
        GET_VAR(j, jD);
        printf("Saisissez les coordonnees de la case d'arrivee : \n");
        GET_VAR(i, iA);
        GET_VAR(j, jA);
	printf("Le mouvement (%hu, %hu) -> (%hu, %hu) est ", 
	       iD, jD, iA, jA); 
	SUIVANT(piece)
     	   CAS(CAVALIER, 
	 	CONDITIONAL_PRINT( (abs(iA - iD) == 1 && abs(jA - jD) == 2)
			|| (abs(iA - iD) == 2 && abs(jA - jD) == 1) );
	       )
     	   CAS(TOUR, 
	        CONDITIONAL_PRINT( iA == iD || jA == jD );
	       )
           CAS(FOU, 
	        CONDITIONAL_PRINT (abs(iA - iD) ==  abs(jA - jD));
	       )
           CAS(DAME, 
	        CONDITIONAL_PRINT(iA == iD 
			   || jA == jD
			   || abs(iA - iD) ==  abs(jA - jD));
	       )
           CAS(ROI, 
                CONDITIONAL_PRINT (abs(iA - iD) <= 1
			 && abs(jA - jD) <= 1);
	       )
        FINSUIVANT(FATAL_ERROR;)
        printf(".\n");    
FINMAIN

#include<stdio.h>
#include<stdlib.h>
#define N 30

/***************************************/

void initialise(char t[], int n)
{
	int i;
	for(i = 0 ; i < n ; i++)
		t[i] = '_';
	t[n] = 0;
}

/***************************************/

int verifie(char t[], char k[], char c)
{
	int i, occ = 0;
	for(i = 0 ; t[i] != 0 ; i++)
	{
		if (t[i] == c && k[i] == '_')
		{	
			k[i] = c;
			occ++;
		}
	}
	return occ;		
}

/***************************************/

int terminePendu(char t[])
{
	int i = 0;	
	while(t[i] != '_' && t[i] != 0)
		i++;
	return t[i] == 0;
}

/***************************************/

int iterationPendu(char t[], char k[])
{
	char lettre, lettresTrouvees;
	printf("Saissez une lettre : ");
	scanf("%c", &lettre);
	getchar();
	lettresTrouvees = verifie(t, k, lettre);	
	printf("%d occurrence(s) de %c trouvee(s)\n", lettresTrouvees, lettre);
	afficheChaine(k);
	printf("\n");
	return lettresTrouvees;
}

/***************************************/

int trouverPendu(char t[], int nbEssais)
{
	char k[N];
	int lettresATrouver = longueur(t) - 1;
	initialise(k, lettresATrouver);
	while(nbEssais-- > 0 && lettresATrouver > 0)
		lettresATrouver -= iterationPendu(t, k);
	return(!lettresATrouver);
}

/***************************************/

void saisieChaine(char t[], int n)
{	
	int i = 0;
	fgets(t, n, stdin);
	while(t[i]!=0)
		i++;
	if (t[i-1] == '\n')
		t[i-1] = 0;
	else
		while(getchar() != '\n');
}

/***************************************/

void jouerPendu()
{
	char t[N];
	printf("Saissez le mot à trouver : ");
	saisieChaine(t, N);
	if (trouverPendu(t, N))	
		printf("You win !\n");
	else
		{
		printf("You lose...\nLe mot est : ");
		afficheChaine(t);
		printf("\n");
		}
}

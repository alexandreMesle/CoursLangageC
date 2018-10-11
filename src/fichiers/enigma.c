#include<stdio.h>
#include<stdlib.h>

#define NB_ROTORS 5
#define NB_LETTERS 26

#define FORWARD 1
#define BACKWARD 2

/***********************************************/

typedef struct rotor
{
  char permutation[NB_LETTERS];
  char permutationInverse[NB_LETTERS];
  char position;
}rotor;

/***********************************************/

typedef struct enigma
{
  rotor rotors[NB_ROTORS];
  char mirror[NB_LETTERS];
}enigma;

/***********************************************/

/*
  Dispose tous les rotors dans leur position de depart.
*/

void initialiseRotors(enigma* e)
{
  int i;
  for(i = 0 ; i < NB_ROTORS ; i++)
    e->rotors[i].position = 0;  
}

/***********************************************/

/*
  Libere la memoire occupee par e.
*/

void enigmaDestroy(enigma* e)
{
  free(e);
}

/***********************************************/

/*
  Alloue la memoire et initialise les champs.
*/

enigma* enigmaCreate()
{
  enigma* e = (enigma*)malloc(sizeof(enigma));
  int i;
  if (e == NULL)
    {
      printf("no memory available\n");
      exit(0);
    }
  initialiseRotors(e);
  for(i = 0 ; i < NB_LETTERS ; i++)
    e->mirror[i] = i;
  return e;
}

/***********************************************/

/*
  Retourne le rang de letter dans l'alphabet, en indicant 
  a partir de 0.
*/

char indexOfLetter(char letter)
{
  return letter - 'a';
}

/***********************************************/

/*
  Retourne la lettre d'indice index dans l'alphabet, 
  'a' est d'indice 0.
 */

char letterOfIndex(char index)
{
  return index + 'a';
}

/***********************************************/

/*
  Fait de la lettre cipherLetter l'image de la lettre 
  d'indice clearIndex par un passage dans le rotor d'indice rotorIndex
  de e.
*/

void setImage(enigma* e, int rotorIndex, int clearIndex, char cipherLetter)
{
  rotor* r = &(e->rotors[rotorIndex]);
  int cipherIndex = indexOfLetter(cipherLetter);
  r->permutation[clearIndex] = cipherIndex;
  r->permutationInverse[cipherIndex] = clearIndex;
}

/***********************************************/

/*
  Fait de firstLetter le reflet de secondLetter.
 */

void setMirror(enigma* e, char firstLetter, char secondLetter)
{
  int firstIndex = indexOfLetter(firstLetter), 
    secondIndex = indexOfLetter(secondLetter);
  e->mirror[firstIndex] = secondIndex;
  e->mirror[secondIndex] = firstIndex;
}

/***********************************************/

/*
  Retourne vrai si et seulement si letter est une minuscule
  de l'alphabet.
 */

int isEncryptable(char letter)
{
  return letter >= 'a' && letter <= 'a' + NB_LETTERS - 1;
}

/***********************************************/

/*
  Affiche les rotors et le miroir de e.
*/

void enigmaPrint(enigma* e)
{
  int i, j;
  for(i = 0 ; i < NB_ROTORS ; i++)
    {
      for(j = 0 ; j < NB_LETTERS ; j++)
	printf("%c ", letterOfIndex(e->rotors[i].permutation[j]));
      printf("\n");
    }
  for(j = 0 ; j < NB_LETTERS ; j++)
    printf("%c ", letterOfIndex(e->mirror[j]));
  printf("\n");
  
}

/***********************************************/

/*
  Fait pivoter le rotor d'indice indexOfRotor de e
  en modifiant sa position de depart. Retourne 
  vrai ssi le rotor est revenu dans sa position 
  initiale.
*/

int rotateRotor(enigma* e, int indexOfRotor)
{
  char* position = &(e->rotors[indexOfRotor].position);
  (*position)++;
  if (*position == NB_LETTERS)
    *position = 0;
  return *position == 0;
}

/***********************************************/

/*
  Fait pivoter le jeu de rotors de e d'une position.
*/

void rotateRotors(enigma* e)
{
  int rotorIndex = 0;
  while(rotorIndex < NB_ROTORS && rotateRotor(e, rotorIndex))
    rotorIndex++;
}

/***********************************************/

/*
  Indice d'entree de la lettre d'indice indexOfLetter 
  dans le rotor r, en tenant compte de la position de 
  ce rotor.
*/

int inputIndex(rotor* r, int indexOfLetter)
{
  return (indexOfLetter + r->position) % NB_LETTERS;
}

/***********************************************/

/*
  Indice de la lettre sortie a l'indice indexOfLetter 
  du rotor r, en tenant compte de la position de 
  ce rotor.
*/

int outputIndex(rotor* r, int indexOfLetter)
{
  return (indexOfLetter - r->position + NB_LETTERS) % NB_LETTERS;
}

/***********************************************/

/*
  Fait passer la lettre d'indice indexOfLetter dans r
  dans la direction direction (FORWARD ou BACKWARD).
 */

int rotorEncrypt(rotor* r, int indexOfLetter, char direction)
{
  indexOfLetter = inputIndex(r, indexOfLetter);
  if (direction == FORWARD)
      indexOfLetter = r->permutation[indexOfLetter];
  else
      indexOfLetter = r->permutationInverse[indexOfLetter];
  return outputIndex(r, indexOfLetter);
}

/***********************************************/

/*
  Fait passer la lettre d'indice indexOfLetter dans 
  le miroir de e.
*/

int mirrorEncrypt(enigma* e, int indexOfLetter)
{
  return e->mirror[indexOfLetter];
}

/***********************************************/

/*
  Chiffre letter avec e, fait ensuite pivoter les rotors
  de e..
*/

char enigmaEncrypt(enigma* e, char letter)
{
  int index = indexOfLetter(letter);
  int i;
  for (i = 0 ; i < NB_ROTORS ; i++)
    index = rotorEncrypt(&(e->rotors[i]), index, FORWARD);
  index = mirrorEncrypt(e, index);
  for (i = NB_ROTORS - 1 ; i >= 0  ; i--)
    index = rotorEncrypt(&(e->rotors[i]), index, BACKWARD);
  rotateRotors(e);
  return letterOfIndex(index);
}

/***********************************************/

/*
  Chiffre le fichier clearFName avec e, ecrit le resultat 
  dans cipherFName.
*/

void encryptFile(enigma* e, char* clearFName, char* cipherFName)
{
  FILE* clear = fopen(clearFName, "r"), *cipher = fopen(cipherFName, "w");
  char a;
  if (clear == NULL)
    {
      printf("Impossible to open %s\n", clearFName);
      exit(0);
    }
  if (cipher == NULL)
    {
      printf("Impossible to open %s\n", cipherFName);
      exit(0);
    }
  while((a = fgetc(clear)) != EOF)
    {
      if (isEncryptable(a))
	a = enigmaEncrypt(e, a);
      fputc(a, cipher);
    }
  if (fclose(clear))
    printf("Impossible to close %s\n.", clearFName);
  if (fclose(cipher))
    printf("Impossible to close %s\n.", cipherFName);
}

/***********************************************/

/*
  Initilialise les NB_ROTORS rotors de e avec deux 
  ecrits dans le fichier rotors.
 */

void loadRotors(enigma* e, FILE* rotors)
{
  int rotorIndex, letterIndex, letter;
  for(rotorIndex = 0 ; rotorIndex < NB_ROTORS ; rotorIndex++)
    {
      for(letterIndex = 0 ; letterIndex < NB_LETTERS ; letterIndex++)
	{
	  if (!isEncryptable(letter = fgetc(rotors)))
	    {
	      printf("Syntax error in rotor file : %c\n", letter);
	      exit(0);
	    }
	  setImage(e, rotorIndex, letterIndex, letter);
	}
      if (fgetc(rotors) != '\n')
	    {
	      printf("Syntax error in rotor file : %c\n", letter);
	      exit(0);
	    }
    }
}

/***********************************************/

/*
  Initilialise le miroir de e avec une ligne du fichier rotors.
 */

void loadMirror(enigma* e, FILE* rotors)
{
  char firstLetter, secondLetter;
  while(isEncryptable(firstLetter = fgetc(rotors)))
    {
      if (!isEncryptable(secondLetter = fgetc(rotors)))
	    {
	      printf("Syntax error in rotor file\n");
	      exit(0);
	    }
      setMirror(e, firstLetter, secondLetter);
    }
}

/***********************************************/

/*
  Cree une machine enigma initialisee avec le contenu du fichier 
  rotorFileName.
*/

enigma* loadFile(char* rotorFileName)
{
  FILE* rotors = fopen(rotorFileName, "r");
  enigma* e; 
  if (rotors == NULL)
    {
      printf("Impossible to open %s\n", rotorFileName);
      exit(0);
    }
  e = enigmaCreate();
  loadRotors(e, rotors);
  loadMirror(e, rotors);
  fclose(rotors);
  return e;
}

/***********************************************/

/*
  Chiffre le fichier clear avec la machine enigma 
  decrite dans rotors, ecrit le resultat dans cipher.
*/

void enigmaRun(char* clear, char* cipher, char* rotors)
{
  enigma* e = loadFile(rotors);
  encryptFile(e, clear, cipher);  
  enigmaDestroy(e);
}

/***********************************************/

int main(int argc, char* argv[])
{
  if (argc == 4)
    enigmaRun(argv[1], argv[2], argv[3]);
  else
    printf("usage : ./enigma source cipher rotorfile\n ");
  return 0;
}

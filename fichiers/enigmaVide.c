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
}

/***********************************************/

/*
  Libere la memoire occupee par e.
*/

void enigmaDestroy(enigma* e)
{
}

/***********************************************/

/*
  Alloue la memoire et initialise les champs.
*/

enigma* enigmaCreate()
{
  return NULL;
}

/***********************************************/

/*
  Retourne le rang de letter dans l'alphabet, en indicant 
  a partir de 0.
*/

char indexOfLetter(char letter)
{
  return 0;
}

/***********************************************/

/*
  Retourne la lettre d'indice index dans l'alphabet, 
  'a' est d'indice 0.
 */

char letterOfIndex(char index)
{
  return 0;
}

/***********************************************/

/*
  Fait de la lettre cipherLetter l'image de la lettre 
  d'indice clearIndex par un passage dans le rotor d'indice rotorIndex
  de e.
*/

void setImage(enigma* e, int rotorIndex, int clearIndex, char cipherLetter)
{
}

/***********************************************/

/*
  Fait de firstLetter le reflet de secondLetter.
 */

void setMirror(enigma* e, char firstLetter, char secondLetter)
{
}

/***********************************************/

/*
  Retourne vrai si et seulement si letter est une minuscule
  de l'alphabet.
 */

int isEncryptable(char letter)
{
  return 0;
}

/***********************************************/

/*
  Affiche les rotors et le miroir de e.
*/

void enigmaPrint(enigma* e)
{
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
  return 0;
}

/***********************************************/

/*
  Fait pivoter le jeu de rotors de e d'une position.
*/

void rotateRotors(enigma* e)
{
}

/***********************************************/

/*
  Indice d'entree de la lettre d'indice indexOfLetter 
  dans le rotor r, en tenant compte de la position de 
  ce rotor.
*/

int inputIndex(rotor* r, int indexOfLetter)
{
  return 0;
}

/***********************************************/

/*
  Indice de la lettre sortie a l'indice indexOfLetter 
  du rotor r, en tenant compte de la position de 
  ce rotor.
*/

int outputIndex(rotor* r, int indexOfLetter)
{
  return 0;
}

/***********************************************/

/*
  Fait passer la lettre d'indice indexOfLetter dans r
  dans la direction direction (FORWARD ou BACKWARD).
 */

int rotorEncrypt(rotor* r, int indexOfLetter, char direction)
{
  return 0;
}

/***********************************************/

/*
  Fait passer la lettre d'indice indexOfLetter dans 
  le miroir de e.
*/

int mirrorEncrypt(enigma* e, int indexOfLetter)
{
  return 0;
}

/***********************************************/

/*
  Chiffre letter avec e, fait ensuite pivoter les rotors
  de e..
*/

char enigmaEncrypt(enigma* e, char letter)
{
  return 0;
}

/***********************************************/

/*
  Chiffre le fichier clearFName avec e, ecrit le resultat 
  dans cipherFName.
*/

void encryptFile(enigma* e, char* clearFName, char* cipherFName)
{
}

/***********************************************/

/*
  Initilialise les NB_ROTORS rotors de e avec deux 
  ecrits dans le fichier rotors.
 */

void loadRotors(enigma* e, FILE* rotors)
{
}

/***********************************************/

/*
  Initilialise le miroir de e avec une ligne du fichier rotors.
 */

void loadMirror(enigma* e, FILE* rotors)
{
}

/***********************************************/

/*
  Cree une machine enigma initialisee avec le contenu du fichier 
  rotorFileName.
*/

enigma* loadFile(char* rotorFileName)
{
  return NULL;
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

#ifndef UTIL_H
#define UTIL_H

/*
  Saisit une chaine de caracteres de longueur sizeMax a l'adresse 
  adr, elimine le caractere de retour a la ligne et vide si necessaire 
  tous les caracteres supplementaires du tampon de saisie. 
 */

void getString(char* adr,  int sizeMax);

/*****************************************************/

/*
  Saisit un entier.
 */

int getInt();

/**********************************************************/

/*
  Echange les chaines de caracteres s1 et s2, de tailles 
  maximales sizeMax.
*/

void swapStrings(char* s1, char* s2, int sizeMax);

#endif

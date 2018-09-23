#include<stdio.h>

typedef struct
{
  int heure;
  int minute;
}heure_t;

/***************************************************/

/*
  Retourne uen structure initialisee avec les 
  valeurs heures et minutes.
*/

heure_t creerHeure(int heures, int minutes)
{
  heure_t result = {0, 0};
  return result;
}

/***************************************************/

/*
  Convertit t en minutes.
*/

int enMinutes(heure_t t)
{
  return 0;
}

/***************************************************/

/*
  Convertit la duree t en heure_t.
*/

heure_t enHeures(int t)
{
  heure_t result = {0, 0};
  return result;
}

/***************************************************/

/*
  Affiche x au format hh:mm
*/

void afficheHeure(heure_t x)
{
}

/***************************************************/

/*
  Additionne a et b.
*/

heure_t additionneHeures(heure_t a, heure_t b)
{
  heure_t result = {0, 0};
  return result;
}

/***************************************************/

/*
  Retourne la valeur a ajouter a x pour obtenir 00:00.
*/

heure_t inverseHeure(heure_t x)
{
  heure_t result = {0, 0};
  return result;
}

/***************************************************/

/*
  Soustrait b a a.
*/

heure_t soustraitHeures(heure_t a, heure_t b)
{
  heure_t result = {0, 0};
  return result;
}

/***************************************************/

/*
  Retourne 1 si a > b, -1 si a < b, 0 si a = b.
 */

int compareHeures(heure_t a, heure_t b)
{
  return 0;
}

/***************************************************/

/*
  Retourne la plus petite des heures a et b.
*/

heure_t minHeure(heure_t a, heure_t b)
{
  heure_t result = {0, 0};
  return result;
}


/***************************************************/

/*
  Pour tester les fonctions...
*/

int main()
{
  return 0;
}

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
  heure_t x = {heures, minutes};
  return x;
}

/***************************************************/

/*
  Convertit t en minutes.
*/

int enMinutes(heure_t t)
{
  return 60 * t.heure + t.minute;
}

/***************************************************/

/*
  Convertit la duree t en heure_t.
*/

heure_t enHeures(int t)
{
  heure_t x = {t/60%12, t%60};
  return x;
}

/***************************************************/

/*
  Affiche x au format hh:mm
*/

void afficheHeure(heure_t x)
{
  printf("%02d:%02d", x.heure, x.minute);
}

/***************************************************/

/*
  Additionne a et b.
*/

heure_t additionneHeures(heure_t a, heure_t b)
{
  return enHeures(enMinutes(a) + enMinutes(b));
}

/***************************************************/

/*
  Retourne la valeur a ajouter a x pour obtenir 00:00.
*/

heure_t inverseHeure(heure_t x)
{
  return enHeures(enMinutes(creerHeure(12, 0)) 
		  - enMinutes(x));
}

/***************************************************/

/*
  Soustrait b a a.
*/

heure_t soustraitHeures(heure_t a, heure_t b)
{
  return additionneHeures(a, inverseHeure(b));
}

/***************************************************/

/*
  Retourne 1 si a > b, -1 si a < b, 0 si a = b.
 */

int compareHeures(heure_t a, heure_t b)
{
  if (a.heure < b.heure)
    return -1;
  if (a.heure > b.heure)
    return 1;
  if (a.minute < b.minute)
    return -1;
  if (a.minute > b.minute)
    return 1;
  return 0;
}

/***************************************************/

/*
  Retourne la plus petite des heures a et b.
*/

heure_t minHeure(heure_t a, heure_t b)
{
  if (compareHeures(a, b) <= 0)
    return a;
  else
    return b;
}

/***************************************************/

/*
  Pour tester les fonctions...
*/

int main()
{
  return 0;
}

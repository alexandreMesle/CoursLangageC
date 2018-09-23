#include<stdio.h>

typedef struct
{
  int heure;
  int minute;
}heure_t;

/**************************************************/

int sommeTab(int* t, int n)
{
  int i, s = 0;
  for(i = 0 ; i < n ; i++)
    s += *(t + i);
  return s;
}

/**************************************************/

int sommeTabRec(int* t, int n)
{
  if (n > 0)
    return *t + sommeTabRec(t + 1, n - 1);
  return 0;
}

/**************************************************/

void initTab(int* t, int n)
{
  int i;
  for(i = 0 ; i < n ; i++)
    *(t + i) = i + 1;
}

/**************************************************/

void initTabRec(int* t, int n)
{
  if (n > 0)
    {
      *(t + n - 1) = n;
      initTabRec(t, n - 1);
    }
}

/**************************************************/

void printTab(int* t, int n)
{
  int i;
  for(i = 0 ; i < n ; i++)
    printf("%d ", *(t + i));
  printf("\n");
}

/**************************************************/

void printTabRec(int* t, int n)
{
  if (n > 0)
    {
      printf("%d ", *t);
      printTabRec(t + 1, n - 1);
    }
  else    
    {
      printf("\n");
    }
}

/**************************************************/

void swap(int* t, int i, int j)
{
  int temp = *(t + i);
  *(t + i) = *(t + j);
  *(t + j) = temp;
}

/**************************************************/

void mirrorTab(int* t, int n)
{
  int i = 0, j = n-1;
  while(i < j)
    {
      swap(t, i, j);
      i++;
      j--;
    }
}

/**************************************************/

void mirrorTabRec(int* t, int n)
{
  if (n > 0)
    {
      swap(t, 0, n-1);
      mirrorTabRec(t + 1, n - 2);
    }
}

/**************************************************/

int find(int* t, int n, int x)
{
  int i;
  for(i = 0 ; i < n ; i++)
    if (*(t + i) == x)
      return 1;
  return 0;
}

/**************************************************/

int findRec(int* t, int n, int x)
{
  if (n == 0)
    return 0;
  if (*t == x)
    return 1;
  return findRec(t + 1, n - 1, x);
}

/**************************************************/

int distinctValues(int* t, int n)
{
  int i, dv = 1;
  for(i = 0 ; i < n - 1 ; i++)
    dv += !find(t + i + 1, n - 1 - i, *(t + i));
  return dv;
}

/**************************************************/

int distinctValuesRec(int* t, int n)
{
  if (n == 0)
    return 0;
  return distinctValuesRec(t + 1, n - 1)
    + (findRec(t + 1, n - 1, *t))? 0 : 1 ;
}

/**************************************************/

heure_t creerHeure(int heures, int minutes)
{
  heure_t x = {heures, minutes};
  return x;
}

/**************************************************/

int enMinutes(heure_t t)
{
  return 60 * t.heure + t.minute;
}

/**************************************************/

heure_t enHeures(int t)
{
  heure_t x = {t/60%12, t%60};
  return x;
}

/**************************************************/

void afficheHeure(heure_t x)
{
  printf("%02d:%02d", x.heure, x.minute);
}

/**************************************************/

heure_t additionneHeures(heure_t a, heure_t b)
{
  return enHeures(enMinutes(a) + enMinutes(b));
}

/**************************************************/

heure_t inverseHeure(heure_t x)
{
  return enHeures(enMinutes(creerHeure(12, 0)) 
		  - enMinutes(x));
}

/**************************************************/

heure_t soustraitHeures(heure_t a, heure_t b)
{
  return additionneHeures(a, inverseHeure(b));
}

/**************************************************/

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

/**************************************************/

heure_t minHeure(heure_t a, heure_t b)
{
  if (compareHeures(a, b) <= 0)
    return a;
  else
    return b;
}

/**************************************************/

void afficheTabHeures(heure_t* t, int n)
{
  if (n > 0)
    {
      afficheHeure(*t);
      printf(" ");
      afficheTabHeures(t + 1, n - 1);
    }
}

/**************************************************/

void initTabHeures(heure_t* t, int n, heure_t depart, heure_t pas)
{
  if (n > 0)
    {
      *t = depart;
      initTabHeures(t + 1, n - 1, 
		    additionneHeures(depart, pas), 
		    pas);
    }
}

/**************************************************/

heure_t sommeTabHeures(heure_t* t, int n)
{
  int i;
  heure_t res = creerHeure(0, 0);
  for(i = 0 ; i < n ; i++)
    res = additionneHeures(res, *(t + i));
  return res;
}

/**************************************************/

heure_t sommeTabHeuresRec(heure_t* t, int n)
{
  if (n == 0)
    return creerHeure(0, 0);
  return additionneHeures(*t, sommeTabHeuresRec(t + 1, n - 1));
}

/**************************************************/

heure_t minTabHeure(heure_t* t, int n)
{
  if (n == 1)
    return *t;
  else
    return minHeure(*t, minTabHeure(t + 1, n-1));
}

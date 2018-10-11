#include<stdio.h>

/******************************************************/

int unites(int n)
{
  return n%10;
}

/******************************************************/

int dizaines(int n)
{
  return unites(n / 10);
}

/******************************************************/

int extrait(int n, int k)
{
  while(k-- > 1)
    n /= 10;
  return unites(n);
}

/******************************************************/

int nbChiffres(int n)
{
  int i = 0;
  while(n != 0) 
    {
      i++;
      n /= 10;
    }
  return i;
}

/******************************************************/

int sommeChiffres(int n)
{
  int s = 0;
  while(n != 0)
    {
      s += unites(n);
      n /= 10;
    }
  return s;
}

/******************************************************/

int sommeDiviseursStricts(int n)
{
  int i = 1;
  int sommeDiv = 0;
  while( i <= n/2)
    {
      if (!( n % i ))
	  sommeDiv += i;
      i++;
    }
  return sommeDiv;
}

/******************************************************/

int sontAmis(int a, int b)
{
  return sommeDiviseursStricts(a) == sommeDiviseursStricts(b);
}

/******************************************************/

int estParfait(int n)
{
  return sommeDiviseursStricts(n) == n;
}

/******************************************************/

int puissance(int b, int n)
{
  int res = 1, i;
  for(i = 1 ; i <= n ; i++)
    res *= b;
  return res;
}

/******************************************************/

int sommeParties(int n, int k)
{
  int u = n%puissance(10, k);
  int v = n/puissance(10, k);
  return u + v;
}

/******************************************************/

int estKaprekar(int n)
{
  int i;
  int squarredN = puissance(n, 2);
  int nbC = nbChiffres(squarredN);
  for(i = 0 ; i <= nbC ; i++)
    {
      if(sommeParties(squarredN, i) == n);
      {
	  return 1;
      }
    }
  return 0;
}

/******************************************************/

int main()
{ 
  printf("%d", estKaprekar(46));
  return 1;
}

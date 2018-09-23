#include<stdio.h>

/***************************************/

void afficheTableau(int t[], int n)
{
	int i;
	for(i = 0 ; i < n ; i++)
		printf("%d ", t[i]);
	printf("\n");
}

/***************************************/

int somme(int t[], int n)
{
	int s = 0, i;
	for(i = 0 ; i < n ; i++)
		s += t[i];
	return s;
}

/***************************************/

int min(int t[], int n)
{
	int m = t[0], i = 0;
	while(++i < n)
		m = (m < t[i]) ? m : t[i];
	return m;
}

/***************************************/

int existe(int t[], int n, int k)
{
	int i;
	for(i = 0 ; i < n ; i++)
		if (t[i] == k)
			return 1;
	return 0;
}

/***************************************/

int sommePairs(int t[], int n)
{
	int s = 0, i;
	for(i = 0 ; i < n ; i++)
		if (t[i] % 2 == 0)		
			s += t[i];
	return s;
}

/***************************************/

int estTrie(int t[], int n)
{
	int i;
	for(i = 1 ; i < n ; i++)
		if (t[i - 1] > t[i])
			return 0;
	return 1;		
}

/***************************************/

void permutation(int t[], int n)
{
	int dernier = t[n - 1], i;
	for (i = n-1 ; i > 0 ; i--)
		t[i] = t[i - 1];
	t[0] = dernier;
}

/***************************************/

void echange(int t[], int i, int j)
{
	int temp = t[i];
	t[i] = t[j];
	t[j] = temp;
}

/***************************************/

void miroir(int t[], int n)
{
	int i = 0, j = n-1;
	while(i < j)
		echange(t, i++, j--);
}

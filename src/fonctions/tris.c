#include<stdio.h>
#include<stdlib.h>
#define N 30

/***************************************/

void echange(int t[], int i, int j)
{
	int temp = t[i];
	t[i] = t[j];
	t[j] = temp;
}

/***************************************/

void ordonne(int T[], int a, int b)
{
	if(T[a] > T[b])
		echange(T, a, b);
}

/***************************************/

void bulle(int T[], int a, int b)
{
	int i;
	for(i = a + 1 ; i <= b ; i++)
		ordonne(T, i-1, i);
}

/***************************************/

void triBulle(int T[], int n)
{
	int i;
	for (i = n-1 ; i > 0 ; i--)
		bulle(T, 0, i);
}

/***************************************/

int indiceDuMin(int T[], int i, int j)
{
	int iMin = i, k;
	for (k = i + 1 ; k <= j ; k++)
		iMin = (T[iMin] <= T[k]) ? iMin : k ;
	return iMin;
}

/***************************************/

void placeMin(int T[], int i, int j, int k)
{
	echange(T, k, indiceDuMin(T, i, j));
}

/***************************************/

void triParSelection(int T[], int n)
{
	int i;
	for (i = 0 ; i < n - 1 ; i++)
		placeMin(T, i, n-1, i);
}

/***************************************/

int main()
{
	int T[N];
	int i;	
	for(i = 0 ; i < N ; i++)
		T[i] = rand()%100;
	afficheTableau(T, N);
	triBulle(T, N);
	afficheTableau(T, N);
	miroir(T, N);	
	afficheTableau(T, N);
	triParSelection(T, N);
	afficheTableau(T, N);
	return 0;
}

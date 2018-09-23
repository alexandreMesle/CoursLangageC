void decalageGauche(int T[], int a, int b)
{
	int i;
	for(i = a ; i <= b ; i++)
	{
		T[i - 1] = T[i];
	}
}

/******************************************************/

int calculeTempsTotalConnexionClient(int C[], int D[], int n, int i)
{
	int j, sum = 0;
	for(j = i ; j < n ; j++)
		if (C[j] == C[i])
			sum += D[j];
	return sum;
}

/******************************************************/

int supprimeDoublons(int C[], int D[], int n, int i)
{
	int nbSuppr = 0, j = i+1;
	while(j < n - nbSuppr)
		if (C[j] == C[i])
		{
			decalageGauche(C, j + 1, n - nbSuppr - 1);
			decalageGauche(D, j + 1, n - nbSuppr - 1);
			nbSuppr++;
		}
		else
			j++;
	return nbSuppr;
}

/******************************************************/

int tempsTotalDeConnexion(int C[], int D[], int n, int i)
{
	D[i] = calculeTempsTotalConnexionClient(C, D, n, i);
	return supprimeDoublons(C, D, n, i);
}

/******************************************************/

int tempsTotauxDeConnexion(int C[], int D[], int n)
{
	int i = 0;
	while(i < n)
		n -= tempsTotalDeConnexion(C, D, n, i++);
	return n;
}

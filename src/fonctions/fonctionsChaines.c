void afficheChaine(char s[])
{
	int i = 0;
	while(s[i] != 0)
		printf("%c", s[i++]);
}

/***************************************/

int longueur(char s[])
{
	int l = 0;
	while(s[l++] != 0);
	return l;
}

/***************************************/

char extrait(char s[], int n)
{
	return s[n - 1];
}

/***************************************/

void subs(char s[], int n, char a)
{
	s[n - 1] = a;	
}

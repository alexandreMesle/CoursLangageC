#include<stdio.h>
#include<stdlib.h>

#define SIZE_TAB 50

/*****************************************/

int divise(int a, int b)
{
    return b % a == 0;
}

/*****************************************/

int power(int b, int n)
{
    if (n == 0)
       return 1;
    return b * power(b, n-1);
}

/*****************************************/

int estPremier(int n, int T[], int k)
{
    int i;
    for (i = 0 ; i < k ; i++)
    {
        if(power(T[i], 2) > n)
            return 1;
        if (divise(T[i], n))
           return 0;
    }
    return 1;
}

/*****************************************/

void trouvePremiers(int T[], int n)
{
     int i;
     int j;
     T[0] = 2;
     for (i = 1 ; i < n ; i++)
     {
         j = T[i - 1] + 1;
         while (!estPremier(j, T, i - 1))
               j++;
         T[i] = j;
     }
}

/*****************************************/

void afficheTab(int T[], int n)
{
     int i;
     for(i = 0 ; i < n ; i++)
           printf("%d ", T[i]);
}

/*****************************************/

void initTab(int T[], int n, int val)
{
     int i;
     for( i = 0 ; i < n ; i++)
          T[i]=val;    
}

/*****************************************/

void decompose(int n, int K[], int T[])
{
     int i;
     initTab(K, SIZE_TAB, 0);
     while(n != 1)
          {
             i = 0;
             while(!divise(T[i], n))
                  i++;
             K[i]++;
             n /= T[i];            
          }  
}

/*****************************************/

int recompose(int K[], int T[], int n)
{
    int res = 1;
    int i;
    for (i = 0 ; i < n  ; i++)
    {
        res *= power(T[i], K[i]);
    }
    return res;
}

/*****************************************/

int min(int a, int b)
{
    if (a < b)
       return a;
    return b;
}

/*****************************************/

void pgcdTab(int A[], int B[], int res[], int n)
{
     int i;
     for (i = 0 ; i < n ; i++)
         res[i] = min(A[i], B[i]);
}

/*****************************************/

int pgcd(int a, int b)
{
    int A[SIZE_TAB];
    int B[SIZE_TAB];
    int T[SIZE_TAB];
    int P[SIZE_TAB];
    trouvePremiers(T, SIZE_TAB);
    decompose(a, A, T);
    decompose(b, B, T);
    pgcdTab(A, B, P, SIZE_TAB);
    return recompose(P, T, SIZE_TAB);
}

/*****************************************/

main()
{
      int a = 90;
      int b = 108;
      printf("pgcd(%d, %d) = %d", a, b, pgcd(a, b));
      getch();
}

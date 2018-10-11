#include<stdio.h>
#include<stdlib.h>

#define SIZE 12
#define TRANSLATION_TRANCHE 5
main()
{
      int t[12];
      int i, j;
      int min, max, somme;
      int temp;
      int vd;
      int meilleureTranche, valeurTranche, debutTranche, finTranche;
      for(i = 0 ; i < SIZE ; i++)
            t[i] = (i*i*i)%SIZE;
      min = t[0];
      max = t[0];
      somme = 0;
      for(i = 1 ; i < SIZE ; i++)
      {
            somme += t[i];
            if(t[i] < min)
                    min = t[i];
            if(t[i] > max)
                    max = t[i];
      }
      printf("plus petit : %d\nplus grand : %d\nsomme : %d\n", 
	     min, max, somme);
      i = 1;
      j = SIZE - 1;
      while(i < j)
      {
              temp = t[i];
              t[i] = t[j];
              t[j] = temp;
              i++; 
              j--;
      }
      vd = SIZE;
      for(i = 0 ; i < SIZE - 1 ; i++ )
              for(j = i + 1 ; j < SIZE ; j++)
                    if(t[i] == t[j])
                            vd--;
      printf("nombre de valeurs distinctes : %d\n", vd);
      for(i = 0 ; i < SIZE ; i++)
            t[i] -= TRANSLATION_TRANCHE;
            
      debutTranche = 0;
      finTranche = 0;
      meilleureTranche = t[0];
      for(i = 0 ; i < SIZE ; i++)
      {
            valeurTranche = 0;
            for (j = i ; j < SIZE ; j++)
            {
                valeurTranche += t[j];
                if (valeurTranche > meilleureTranche)
                {
                                  meilleureTranche = valeurTranche;
                                  debutTranche = i;
                                  finTranche = j;
                }
            }
      }
      printf("le tableau est \n%d", t[0]);
      for(i = 1 ; i < SIZE ; i++)
            printf(" -> %d", t[i]);
      printf("\nla plus grande tranche est :\n%d ", t[debutTranche]);
      for(i = debutTranche + 1 ; i < finTranche ; i++)
            printf(" -> %d", t[i]);
      getch();
}

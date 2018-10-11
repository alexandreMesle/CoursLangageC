#include<stdio.h>

void additionne(int a, int b, int* res)
{
  /* Ecrivez le corps du sous-programme ici */
    

}

int main()
{
  int i = 2;
  int j = 3;
  int k;
  additionne(i, j, &k);
  printf("k = %d\n", k); // doit afficher "k = 5"
  return 0;
}

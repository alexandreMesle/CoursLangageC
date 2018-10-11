#include<stdio.h>

int main()
{
  float dommages, franchise, remboursement;
  printf("Saisissez le montant des dommages\n");
  scanf("%f", &dommages);
  franchise = dommages * 0.1;
  if(franchise > 4000)
    franchise = 4000;
  remboursement  = dommages - franchise;
  printf("Montant de la franchise : %.2f\n", franchise);
  printf("Montant rembourse : %.2f\n", remboursement);
  return 0;
}

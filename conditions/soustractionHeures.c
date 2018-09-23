#include<stdio.h>

int main()
{
  int heureDebut, heureFin, minuteDebut, minuteFin, 
    heureEcart, minuteEcart;
  printf("Heure debut (hh:mm) ? ");
  scanf("%d:%d", &heureDebut, &minuteDebut);
  printf("Heure fin (hh:mm) ? ");
  scanf("%d:%d", &heureFin, &minuteFin);
  heureEcart = heureFin - heureDebut;
  minuteEcart = minuteFin - minuteDebut;
  if (minuteEcart < 0)
    {
      heureEcart--;
      minuteEcart += 60;
    }
  printf("Duree de l'intervalle : %2.2d:%2.2d\n", 
	 heureEcart, minuteEcart );
  return 0;
}

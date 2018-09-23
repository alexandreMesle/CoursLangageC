#include<stdio.h>

int main()
{
  float note;
  printf("Saisissez votre note\n");
  scanf("%f", &note);
  if(note < 8)
    printf("Ajourne");
  if(note >= 8 && note < 10)
    printf("Rattrapage");
  if(note >= 10)
    printf("Admis");
  printf("\n");
  return 0;
}

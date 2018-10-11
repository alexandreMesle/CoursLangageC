#include<stdio.h>

int main()
{
  unsigned short age;
  printf("T'as quel age ?\n");
  scanf("%hu", &age);
  if(age >= 18)
    printf("T'es majeur.");
  else
    printf("T'es mineur.");
  printf("\n");
  return 0;
}

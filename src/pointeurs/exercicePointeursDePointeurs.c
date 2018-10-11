#include<stdio.h>

int main()
{
  long A, B, C, D;
  long *p1, *p2, *p3;
  long **pp;
  A = 10 ; 
  B = 20 ; 
  C = 30 ; 
  D = 40;
  p1 = &A;
  p2 = &B;
  p3 = &B;
  *p1 = (*p1 + 1);
  *p3 = (*p2 + D);
  p3 = &C;
  *p3 = (*p2 + D);
  printf("A = %ld, B = %ld, C = %ld, D = %ld\n", A, B, C, D);
  pp = &p3;
  printf("%ld\n", **pp);
  return 0;
}

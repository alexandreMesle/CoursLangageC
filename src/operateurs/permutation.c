#include<stdio.h>

int main()
{
  int a = 1;
  int b = 2;
  printf("a = %d, b = %d\n", a, b);
  // a = x, b = y
  a ^= b; // a = x^y, b = y
  b ^= a; // a = x^y, b = y ^ x ^ y = x
  a ^= b; // a = x^y^x = y, b = x
  // a = y, b = x
  printf("a = %d, b = %d\n", a, b);
  return 0;
}

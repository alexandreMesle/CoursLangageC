#include<stdio.h>

void procedure1()
{
  printf("debut procedure 1\n");
  printf("fin procedure 1\n");
}

void procedure2()
{
  printf("debut procedure 2\n");
  procedure1();
  printf("fin procedure 2\n");
}

void procedure3()
{
  printf("debut procedure 3\n");
  procedure1();
  procedure2();
  printf("fin procedure 3\n");
}

int main()
{
  printf("debut main\n");
  procedure2();
  procedure3();
  printf("fin main\n");
  return 0;
}

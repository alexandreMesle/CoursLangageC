#include<stdio.h>
#include<stdlib.h>

void initTab(int* t, int n)
{
  if (n > 0)
    {
      initTab(t + 1, n - 1);
      *t = ((n > 1) ? *(t+1) : 0) - rand() % 100;
    }
}

int* randomTab(int n)
{
  int* t = (int*) malloc (n * sizeof(int));
  if (t == 0)
    return NULL;
  initTab(t, n);
  return t;
}

void afficheTab(int* t, int n)
{
  if (n <= 0)
    printf("\n");
  else
    {
      printf("%d ", *t);
      afficheTab(t + 1, n - 1);
    }
}

int find(int* t, int n, int x)
{
  int res, middle;
  if (n <= 0)
    return -1;
  middle = n/2;
  if (*(t + middle) == x)
    return middle;
  if (*(t + middle) > x)
    return find(t, middle, x);
  res = find(t + middle + 1, n - middle - 1, x);
  return res + ((res == -1) ? 0 : middle + 1);
}

int main()
{
  int* t = randomTab(10);
  if (t == NULL)
    return 1;
  afficheTab(t, 10);
  printf("%d\n", find(t, 10, -289));
  return 0;
}

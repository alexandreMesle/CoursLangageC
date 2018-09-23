#include<stdio.h> 

/**************************************************************/ 
typedef struct maillon 
{ 
  int data; 
  struct maillon* next; 
}maillon; 

/**************************************************************/ 

int main() 
{ 
  maillon m, p, q, r; 
  maillon* ptr; 
  m.data = 1; 
  p.data = 2; 
  q.data = 3; 
  r.data = 4; 
  m.next = &p; 
  p.next = &q; 
  q.next = &r; 
  r.next = NULL;
  for (ptr = &m ; ptr != NULL ; ptr = ptr->next) 
    printf("data = %d\n", ptr->data); 
  return 0;
}

#include <stdio.h>

#include "list.h"

int main() {
  printf("Tests for linked list implementation\n");
  
  list_t* mylist = list_alloc();
  list_print(mylist);
  
  list_add_to_front(mylist, 5);
  list_add_to_front(mylist, 4);
  list_add_to_front(mylist, 3);
  list_add_to_front(mylist, 2);
  list_add_to_front(mylist, 1);
  
  list_add_to_back(mylist, 11);
  list_add_to_back(mylist, 12);
  list_add_to_back(mylist, 13);
  list_add_to_back(mylist, 14);
  list_add_to_back(mylist, 15);
  
  list_add_at_index(mylist, 10, 5);
  list_add_at_index(mylist, 9, 5);
  list_add_at_index(mylist, 8, 5);
  list_add_at_index(mylist, 7, 5);
  list_add_at_index(mylist, 6, 5);
  list_print(mylist);
  
  printf("\n");
  
  printf("Index: 5 | Element at Index: %d\n", list_get_elem_at(mylist, 5));
  printf("Index: 9 | Element at Index: %d\n", list_get_elem_at(mylist, 9));
  printf("Index: 14 | Element at Index: %d\n", list_get_elem_at(mylist, 14));
  
  printf("16 in list? : %d\n", list_get_index_of(mylist, 16));
  printf("11 in list? : %d\n", list_get_index_of(mylist, 11));
  printf("0 in list? : %d\n", list_get_index_of(mylist, 0));
  

  list_remove_from_back(mylist);
  list_remove_from_back(mylist); 
  
  list_remove_from_front(mylist);
  list_remove_from_front(mylist);
  list_print(mylist);
  
  printf("\n");
  
  list_remove_at_index(mylist, 4);
  list_remove_at_index(mylist, 7);
  list_print(mylist);
  
  return 0;
}

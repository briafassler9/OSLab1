// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t* list = malloc(sizeof(list_t));
  list->head = NULL;
  return list;
}

void list_free(list_t *l) {
  while(l->head != NULL) {
    node_t * temp = l->head;
    l->head = l->head->next;
    free(temp);
  }
  return;
}

void list_print(list_t *l) {
  node_t *cur = l->head;
  
  while(cur != NULL) {
    printf("%d ", cur->value);
    cur = cur->next;
  }
}

int list_length(list_t *l) { 
  node_t* cur = l->head;
  int count = 0;
  
  while(l->head != NULL){
    count++;
    l->head = l->head->next;
  }
  l->head = cur;
  return count;
}

void list_add_to_back(list_t *l, elem value) {
  node_t* cur = l->head;
  
  if (l->head == NULL) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    l->head = new_node;
    return;
  } else {
    while(l->head->next != NULL) {
      l->head = l->head->next;
    }
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    l->head->next = new_node;
  }
  l->head = cur;
  return;
}

void list_add_to_front(list_t *l, elem value) {
  node_t *head = malloc(sizeof(node_t));
  head->value = value;
  head->next = l->head;
  l->head = head;
}

void list_add_at_index(list_t *l, elem value, int index) {
  node_t* cur = l->head;
  if (index == 0){
    list_add_to_front(l, value);
    return;
  }
  if(index == list_length(l)-1){
    list_add_to_back(l, value);
    return;
  }
  if(index >= list_length(l)){
    return;
  }
  
  while(index != 1){
    index--;
    l->head = l->head->next;
  }
  
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = l->head->next;
  l->head->next = new_node;
  l->head = cur;
}

elem list_remove_from_back(list_t *l) { 
  node_t* cur = l->head;
  if (list_length(l) == 1){
    list_remove_from_front(l);
  }
  
  while(l->head->next->next != NULL){
    l->head = l->head->next;
  }
  
  free(l->head->next);
  l->head->next = NULL;
  l->head = cur;
  return 1; 
}

elem list_remove_from_front(list_t *l) { 
  node_t *temp = l->head;
  l->head = l->head->next;
  free(temp);
  return l->head->value; 
}

elem list_remove_at_index(list_t *l, int index) { 
    node_t* cur = l->head;
  
    while(index != 1) {
      index--;
      l->head = l->head->next;
    }
  node_t* temp = l->head->next;
  l->head->next = l->head->next->next;
  l->head = cur; 
  
  free(temp);
  return -1;
}

bool list_is_in(list_t *l, elem value) { 
  node_t* cur = l->head;
  
  while(l->head != NULL){
    if (l->head->value != value){
      l->head = l->head->next;
    } else {
      l->head = cur;
      return true;
    }
  }
  l->head = cur;
  return false; 
}

elem list_get_elem_at(list_t *l, int index) { 
  node_t* cur = l->head;
  while (l->head != NULL) {
    if(index != 0){
      l->head = l->head->next;
    } else {
      int temp = l->head->value;
      l->head = cur;
      return temp;
    }
    index -= 1;
  } 
  l->head = cur;
  return -1;
}

int list_get_index_of(list_t *l, elem value) { 
  node_t* cur = l->head;
  
  while (l->head != NULL) {
    if (l->head->value != value){
      l->head = l->head->next;
    }
    else {
      l->head = cur;
      return true;
    }
  }
  l->head = cur;
  return false; 
}


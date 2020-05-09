#include<stdlib.h>
#include<stdio.h>
#include <string.h> 
#include <ctype.h>
#include "array_void.h"

Object find_sum(Object num1, Object num2) {
  int sum = *(int *)num1 +  *(int *)num2;
  return save_number(sum);
};

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer) {
  for(int i = 0; i < src->length; i++) {
    init = (*reducer)(init,src->array[i]);
  }
  return init;
};

Bool is_vowel(Object letter) {
  char ch = tolower(*(char *)letter);
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
};

Bool is_even_num(Object num) {
  return *(int *)num % 2 == 0;
};

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate) {
  Object list[src->length];
  int count = 0;
  for(int i = 0; i < src->length; i++) {
    if((*predicate)(src->array[i])) {
      list[count] = src->array[i];
      count++;
    }
  }
   ArrayVoid_ptr result = create_void_array(count);
   for(int i = 0; i < count; i++) {
     result->array[i] = malloc(sizeof(Object));
     result->array[i] = list[i];
     }
  return result;
};


Object convert_to_lower_case(Object letter) {
  char *result = malloc(sizeof(char));
  *result = tolower(*(char *)letter);
  return result;
};

Object increment_by_one(Object num) {
  int *result = malloc(sizeof(int));
  *result = *(int *)num + 1;
  return result;
};

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper) {
  ArrayVoid_ptr result = create_void_array(src->length);
  for(int i = 0; i < src->length; i++) {
    result->array[i] = (*mapper)(src->array[i]);
  }
  return result;
};

ArrayVoid_ptr create_void_array(int length) {
  ArrayVoid_ptr list = malloc(sizeof(ArrayVoid));
  list->array = malloc(sizeof(Object) * length);
  list->length = length;
  return list;
};

void display_numbers(Array_ptr list) {
  for(int i = 0; i < list->length; i++) {
    printf("%d \n",list->array[i]);
  }
};

Object save_number(int num) {
  char *result = malloc(sizeof(int));
  *result = num;
  return result;
};

Object save_character(char letter) {
  char *result = malloc(sizeof(char));
  *result = letter;
  return result;
};

void display_char(Object letter) {
  printf("%c \n", *(char *)letter);
};

void display_num(Object num) {
  printf("%d \n",*(int *)num);
};

void display_void_array(ArrayVoid_ptr result,Display_data displayer ) {
  for(int i = 0; i < result->length; i++) {
    (*displayer)(result->array[i]);
  }
};
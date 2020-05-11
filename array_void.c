#include<stdlib.h>
#include<stdio.h>
#include<string.h>
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
      list[count] = malloc(sizeof(Object));
      memcpy(list[count],src->array[i],sizeof(Object));
      count++;
    }
  }
   ArrayVoid_ptr result = create_void_array(count);
   for(int i = 0; i < count; i++) {
   result->array[i] = list[i];
   }
  return result;
};


Object convert_to_lower_case(Object value) {
  char *letter = malloc(sizeof(char));
  *letter = tolower(*(char *)value);
  return letter;
};

Object increment_by_one(Object value) {
  int *num = malloc(sizeof(int));
  *num = *(int *)value + 1;
  return num;
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

Object save_number(int value) {
  int *num = malloc(sizeof(int));
  *num = value;
  return num;
};

Object save_character(char value) {
  char *letter = malloc(sizeof(char));
  *letter = value;
  return letter;
};

void display_char(Object letter) {
  printf("%c \n", *(char *)letter);
};

void display_num(Object num) {
  printf("%d \n",*(int *)num);
};

void display_array(ArrayVoid_ptr result,Display_data displayer ) {
  for(int i = 0; i < result->length; i++) {
    (*displayer)(result->array[i]);
  }
};
#include<stdlib.h>
#include<stdio.h>
#include <ctype.h>
#include "array_void.h"

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
#include<stdlib.h>
#include "array.h"

Bool is_even(int num) {
  return num % 2 == 0;
};

Array_ptr filter(Array_ptr src, Predicate predicate) {
  int count = 0,index= 0;
  for(int i = 0; i < src->length; i++) {
    if((*predicate)(src->array[i])) count++;
  }
  Array_ptr result = create_array(count);
  for(int i = 0; i < src->length; i++) {
    if((*predicate)(src->array[i])) {
      result->array[index] = src->array[i];
      index++;
    }
  }
  return result;
};

int find_square(int value) {
  return value * value;
};

Array_ptr map(Array_ptr src, Mapper mapper) {
  Array_ptr result = create_array(src->length);
  for(int i = 0; i < src->length; i++) {
    result->array[i] = (*mapper)(src->array[i]);
  }
  return result;
};

Array_ptr create_array(int length) {
  Array_ptr number_list = malloc(sizeof(Array));
  number_list->array = malloc(sizeof(int) * length);
  number_list->length = length;
  return number_list;
};
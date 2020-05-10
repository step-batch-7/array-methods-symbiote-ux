#include<assert.h>
#include<stdio.h>
#include "../array_void.h"

void assert_reduce_void(void) {
  printf("Reduce_Void\n");
  printf("should give initial value if the list is empty\n");
  ArrayVoid_ptr src = create_void_array(0);
  ReducerVoid reducer = &find_sum;
  Object sum = reduce_void(src,save_number(0),reducer);
  assert(*(int *)sum == 0);
  printf("Passed\n");

  printf("should give the sum of all numbers in the list\n");
  src = create_void_array(3);
  src->array[0] = save_number(5);
  src->array[1] = save_number(6);
  src->array[2] = save_number(8);
  sum = reduce_void(src,save_number(0),reducer);
  assert(*(int *)sum == 19);
  printf("Passed\n");
};


void assert_filter_void(void) {
  printf("Filter_void\n");
  ArrayVoid_ptr src = create_void_array(3);
  src->array[0] = save_number(5);
  src->array[1] = save_number(6);
  src->array[2] = save_number(8);
  PredicateVoid predicates[] = {&is_even_num,&is_vowel};
  ArrayVoid_ptr result = filter_void(src,predicates[0]);
  assert(result->length == 2);
  assert(*(int *)result->array[0] == 6);
  assert(*(int *)result->array[1] == 8);
  printf("Passed\n");

  printf(" should give vowels in the list :\n");
  src = create_void_array(5);
  src->array[0] = save_character('A');
  src->array[1] = save_character('b');
  src->array[2] = save_character('C');
  src->array[3] = save_character('d');
  src->array[4] = save_character('e');
  result = filter_void(src,predicates[1]);
  assert(result->length == 2);
  assert(*(int *)result->array[0] == 'A');
  assert(*(int *)result->array[1] == 'e');
  printf("Passed\n");
};

void assert_map_void(void) {
  printf("Map_Void\n");
  printf("should increment each number by one in the list\n");
  ArrayVoid_ptr src = create_void_array(3);
  src->array[0] = save_number(5);
  src->array[1] = save_number(6);
  src->array[2] = save_number(8);
  MapperVoid mappers[] = {&increment_by_one,&convert_to_lower_case};
  ArrayVoid_ptr result = map_void(src,mappers[0]);
  assert(result->length == 3);
  assert(*(int *)result->array[0] == 6);
  assert(*(int *)result->array[1] == 7);
  assert(*(int *)result->array[2] == 9);
  printf("Passed\n");

  printf("should convert characters into lower case\n");
  src = create_void_array(3);
  src->array[0] = save_character('X');
  src->array[1] = save_character('Y');
  src->array[2] = save_character('A');
  result = map_void(src, mappers[1]);
  assert(result->length == 3);
  assert(*(int *)result->array[0] == 'x');
  assert(*(int *)result->array[1] == 'y');
  assert(*(int *)result->array[2] == 'a');
  printf("Passed\n");
};

int main(void) {
  assert_map_void();
  assert_filter_void();
  assert_reduce_void();
  return 0;
}
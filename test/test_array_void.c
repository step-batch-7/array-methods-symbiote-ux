#include<assert.h>
#include<stdio.h>
#include "../array_void.h"

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
  // assert_filter_void();
  // assert_reduce_void();
  return 0;
}
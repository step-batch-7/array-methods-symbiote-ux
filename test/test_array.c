#include<assert.h>
#include<stdio.h>
#include "../array.h"

void assert_reduce(void) {
  printf("Reduce\n");
  printf("should give initial value for the empty list\n");
  Array_ptr numbers = create_array(0);
  Reducer reducer = &calc_sum;
  int sum = reduce(numbers,0,reducer);
  assert(sum == 0);
  printf("Passed\n");

  printf("should give the sum of all numbers\n");
  numbers = create_array(2);
  numbers->array[0] = 5;
  numbers->array[1] = 6;
  sum = reduce(numbers,0,reducer);
  assert(sum == 11);
  printf("Passed\n");
};

void assert_filter(void) {
  printf("Filter\n");
  printf("should filter the empty list\n");
  Array_ptr numbers = create_array(0);
  Predicate predicate = &is_even;
  Array_ptr result = filter(numbers,predicate);
  assert(result->length == 0);
  printf("Passed\n");

  printf("should give even number in the list\n");
  numbers = create_array(3);
  numbers->array[0] = 5;
  numbers->array[1] = 6;
  numbers->array[2] = 7;
  result = filter(numbers,predicate);
  assert(result->array[0] == 6);
  assert(result->length == 1);
  printf("Passed\n");
};

void assert_map(void) {
  printf("Map\n");
  printf("should map the empty list\n");
  Array_ptr numbers = create_array(0);
  Mapper mapper = &find_square;
  Array_ptr result = map(numbers,mapper);
  assert(result->length == 0);
  printf("Passed\n");

  printf("should give square of each number in the list\n");
  numbers = create_array(3);
  numbers->array[0] = 5;
  numbers->array[1] = 6;
  numbers->array[2] = 7;
  result = map(numbers,mapper);
  assert(result->array[0] == 25);
  assert(result->array[1] == 36);
  assert(result->array[2] == 49);
  assert(result->length == 3);
  printf("Passed\n");
};

int main(void) {
  assert_map();
  assert_filter();
  assert_reduce();
  return 0;
}
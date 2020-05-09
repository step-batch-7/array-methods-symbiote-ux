#include <stdio.h>
#include "array.h"

void display_numbers(Array_ptr list) {
  for(int i = 0; i < list->length; i++) {
    printf("%d \n",list->array[i]);
  }
};

int main(void) {
  Array_ptr numbers = create_array(3);
  numbers->array[0] = 5;
  numbers->array[1] = 6;
  numbers->array[2] = 7;
  printf("Numbers in the list are: \n");
  display_numbers(numbers);
  Mapper mapper = &find_square;
  Array_ptr result = map(numbers,mapper);
  printf("Square of each number in the list is:\n");
  display_numbers(result);
  Predicate predicate = &is_even;
  Array_ptr even_num_list = filter(numbers,predicate);
  printf("Even Numbers in the list:\n");
  display_numbers(even_num_list);
  Reducer reducer = &calc_sum;
  int sum = reduce(numbers,0,reducer);
  printf("Sum of numbers : %d \n",sum);
  return 0;
}
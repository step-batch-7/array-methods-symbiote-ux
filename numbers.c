#include <stdio.h>
#include<stdlib.h>
#include "array.h"
#include "array_void.h"

void create_num_list(ArrayVoid_ptr src) {
  for(int i = 0; i < src->length; i++) {
    int *num = malloc(sizeof(int));
    *num = (i + 1) * 2;
    src->array[i] = num;
  }
};

void display_numbers(Array_ptr list) {
  for(int i = 0; i < list->length; i++) {
    printf("%d \n",list->array[i]);
  }
};

int main(void) {
  // Array_ptr numbers = create_array(3);
  // numbers->array[0] = 5;
  // numbers->array[1] = 6;
  // numbers->array[2] = 7;

  // printf("Numbers in the list are: \n");
  // display_numbers(numbers);

  // Mapper mapper = &find_square;
  // Array_ptr result = map(numbers,mapper);
  // printf("Square of each number in the list is:\n");
  // display_numbers(result);

  // Predicate predicate = &is_even;
  // Array_ptr even_num_list = filter(numbers,predicate);
  // printf("Even Numbers in the list:\n");
  // display_numbers(even_num_list);
  
  // Reducer reducer = &calc_sum;
  // int sum = reduce(numbers,0,reducer);
  // printf("Sum of numbers : %d \n",sum);

  ArrayVoid_ptr src = create_void_array(3);
  create_num_list(src);
  MapperVoid mapper = &increment_by_one;
  Display_data displayer = &display_num;
  
  printf("Numbers list : \n");
  display_void_array(src,displayer);

  ArrayVoid_ptr result1 = map_void(src, mapper);
  printf("Numbers after incremented by one : \n");
  display_void_array(result1,displayer);
  return 0;
}
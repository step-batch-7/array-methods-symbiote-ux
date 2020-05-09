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
  return 0;
}
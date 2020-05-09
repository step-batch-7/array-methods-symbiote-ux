#include <stdio.h>
#include<stdlib.h>
#include "array.h"
#include "array_void.h"

int main(void) {
  Array_ptr numbers = create_array(3);
  numbers->array[0] = 5;
  numbers->array[1] = 6;
  numbers->array[2] = 7;

  printf("Numbers in the list are: \n");
  display_numbers(numbers);

  Mapper mapper1 = &find_square;
  Array_ptr result1 = map(numbers,mapper1);
  printf("Square of each number in the list is:\n");
  display_numbers(result1);

  Predicate predicate1 = &is_even;
  Array_ptr even_num_list = filter(numbers,predicate1);
  printf("Even Numbers in the list:\n");
  display_numbers(even_num_list);
  
  Reducer reducer1 = &calc_sum;
  int sum1 = reduce(numbers,0,reducer1);
  printf("Sum of numbers : %d \n",sum1);

  ArrayVoid_ptr src = create_void_array(3);
  MapperVoid mappers[] = {&increment_by_one,&convert_to_lower_case};
  Display_data displayers[] = {&display_num,&display_char};
  PredicateVoid predicates[] = {&is_even_num,&is_vowel};
  ReducerVoid reducer = &find_sum;

  src->array[0] = save_character('X');
  src->array[1] = save_character('Y');
  src->array[2] = save_character('A');

  ArrayVoid_ptr result = map_void(src, mappers[1]);

  printf("Character list : \n");
  display_void_array(src,displayers[1]);

  printf("Characters After conversion to lower case :\n");
  display_void_array(result,displayers[1]);

  printf("Numbers list : \n");
  src = create_void_array(3);
  src->array[0] = save_number(5);
  src->array[1] = save_number(6);
  src->array[2] = save_number(8);
  display_void_array(src,displayers[0]);

  printf("Numbers after incremented by one : \n");
  result = map_void(src,mappers[0]);
  display_void_array(result,displayers[0]);

  printf("Sum of all Numbers in the list\n");
  Object sum = reduce_void(src,save_number(0),reducer);
  printf("%d \n",*(int *)sum);

  printf("All Even numbers in the list :\n");
  result = filter_void(src,predicates[0]);
  display_void_array(result,displayers[0]);

  src = create_void_array(5);
  src->array[0] = save_character('A');
  src->array[1] = save_character('b');
  src->array[2] = save_character('C');
  src->array[3] = save_character('d');
  src->array[4] = save_character('e');

  printf("Character list : \n");
  display_void_array(src,displayers[1]);

  result = filter_void(src,predicates[1]);
  printf("Vowels in the list :\n");
  display_void_array(result,displayers[1]);
  return 0;
}
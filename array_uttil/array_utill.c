#include "array_utill.h"
#include "assert.h"
#include <stdlib.h>

void test_for_create(){
	Array_util array;
	int *numbers;
	array = create(4,13);
	assert(array.length == 13);
	assert(array.type_size == 4);

	numbers = (int *)(array.base);
	numbers[0]=5;
	assert(numbers[0]==5);
	dispose(array);
}

void test_for_resize(){
	Array_util array, array2;
	Array_util resized_array;
	int *numbers;
	int *another_numbers;


	array = create(4,10);
	numbers = (int *)(array.base);
	numbers[0]=5;
	resized_array = resize(array,20);

	assert(array.length==10);
	assert(resized_array.length == 20);
	another_numbers = (int *)(resized_array.base);
	assert(numbers[0]==another_numbers[0]);

	resized_array = resize(resized_array,15);
	assert(resized_array.length == 15);
	dispose(resized_array);
}

void push_element_in_array(Array_util array){
	int * numbers;
	numbers = (int *)(array.base);
	for (int index = 0; index < array.length; index++)
		numbers[index] = 65 + index;
}

void test_for_areEqual(){
	Array_util firstArray,secondArray;
	firstArray = create(4,10);
	secondArray = create(4,10);
	assert(areEqual(firstArray,secondArray)==1);
	firstArray = resize(firstArray,8);
	assert(areEqual(firstArray,secondArray)==0);
	firstArray = create(8,10);
	assert(areEqual(firstArray,secondArray)==0);
	firstArray = create(4,10);
	push_element_in_array(firstArray);
	assert(areEqual(firstArray,secondArray)==0);
	push_element_in_array(secondArray);
	assert(areEqual(firstArray,secondArray)==1);
	dispose(firstArray);
	dispose(secondArray);
}

void test_for_find_index(){
	Array_util array;
	array = create(1,2);
	char * characters = (char *)(array.base);
	characters[0]='A';
	characters[1]='B';
	char first_element = 'A';
	char second_element = 'B';
	char extra_element = 'C';
	assert(findIndex(array,&first_element)==0);
	assert(findIndex(array,&second_element)==1);
	assert(findIndex(array,&extra_element)==-1);
	dispose(array);
}

int isEven(void* hint, void* item){
	int * number = (int *)(item);
	return !(*number % 2);
}

int isDivisible(void* hint, void* item){
	int * numerator = (int *)(item);
	int * denominator = (int *)(hint);
	if(( *numerator % *denominator ) == 0) return 1;
	return 0;
}

void test_for_find_first(){
	Array_util array = create(4,5);
	int *numbers = (int *)(array.base);

	numbers[0] = 1;
	numbers[1] = 3;
	numbers[2] = 6;
	numbers[3] = 8;
	numbers[4] = 5;

	void * even_hint = NULL;
	int * even_result = (int *)findFirst(array, &isEven, even_hint);
	assert(*even_result == 6);
	int divide_hint = 3;
	int * divide_result = (int *)findFirst(array, &isDivisible, &divide_hint);
	assert(*divide_result == 3);
	dispose(array);
}

void test_for_find_last(){
	Array_util array;
	array = create(4,5);
	int *numbers = (int *)(array.base);

	numbers[0] = 1;
	numbers[1] = 3;
	numbers[2] = 6;
	numbers[3] = 8;
	numbers[4] = 5;
	void * even_hint = NULL;
	int * even_result = (int *)findLast(array, &isEven, even_hint);
	assert(*even_result == 8);
	int divide_hint = 1;
	int * divide_result = (int *)findLast(array, &isDivisible, &divide_hint);
	assert(*divide_result == 5);
	dispose(array);


}
void test_for_reverse(){
	Array_util array,reversed_array;
	array = create(4,5);
	int * numbers_of_array = (int *)(array.base);
	numbers_of_array[0]=0;
	numbers_of_array[1]=1;
	numbers_of_array[2]=2;
	numbers_of_array[3]=3;
	numbers_of_array[4]=4;
	reversed_array = reverse_array(array);
	int * numbers_of_reversed_array = (int *)(reversed_array.base);
	assert(numbers_of_reversed_array[0]==4);
	assert(numbers_of_reversed_array[3]==1);
	assert(numbers_of_array[3]==1);
	dispose(array);
}

void test_for_count(){
	Array_util array;
	array = create(4,5);
	int *numbers = (int *)(array.base);

	numbers[0] = 1;
	numbers[1] = 3;
	numbers[2] = 6;
	numbers[3] = 8;
	numbers[4] = 5;
	void * even_hint = NULL;
	int even_result_count = count(array, &isEven, even_hint);
	assert(even_result_count == 2);
	int divide_hint = 1;
	int divide_result_count = count(array, &isDivisible, &divide_hint);
	assert(divide_result_count == 5);
	dispose(array);
}

void test_for_filter(){
	Array_util array = create(4,5);
	int *numbers = (int *)(array.base);

	numbers[0] = 1;
	numbers[1] = 3;
	numbers[2] = 6;
	numbers[3] = 8;
	numbers[4] = 5;
	Array_util destination_array_isEven = create(4,5);
	void * even_hint = NULL;
	int maxItems = 5;
	int size = filter(array, &isEven , even_hint, destination_array_isEven.base , maxItems );
	assert(((int **)destination_array_isEven.base)[0] == &numbers[2]);
	assert(((int **)destination_array_isEven.base)[1] == &numbers[3]);
	assert(size = 2);
}

void use_of_dispose(){
	Array_util array;
	array = create(4,13);
	dispose(array);
}

int main(int argc, char const *argv[]){
	test_for_create();
	test_for_resize();
	test_for_areEqual();
	test_for_find_index();
	test_for_find_first();
	test_for_find_last();
	test_for_reverse();
	test_for_count();
	test_for_filter();
	use_of_dispose();
	return 0;
}
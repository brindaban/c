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
void test_for_find_first(){
	Array_util array = create(4,5);
	int *numbers = (int *)(array.base);

	numbers[0] = 1;
	numbers[1] = 3;
	numbers[2] = 6;
	numbers[3] = 8;
	numbers[4] = 5;

	void * hint = NULL;
	int * result = (int *)findFirst(array, &isEven, hint);
	assert(*result == 6);
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
	use_of_dispose();
	return 0;
}
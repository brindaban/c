#include "array_utill.h"
#include "assert.h"

void test_for_create(){
	Array_util array;
	int *numbers;
	array = create(4,13);
	assert(array.length == 13);
	assert(array.type_size == 4);

	numbers = (int *)(array.base);
	assert(numbers[0]==0);
}

void test_for_resize(){
	Array_util array;
	Array_util resized_array;

	array = create(4,10);
	resized_array = resize(array,20);

	assert(resized_array.length == 20);

}

int main(int argc, char const *argv[]){
	test_for_create();
	test_for_resize();
	return 0;
}
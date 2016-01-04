#include "array_utill.h"
#include "assert.h"

void test_for_create(){
	Array_util array;
	array = create(4,13);
	assert(array.length == 13);
	assert(array.type_size == 4);
}


int main(int argc, char const *argv[]){
	test_for_create();
	return 0;
}
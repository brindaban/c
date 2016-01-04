#include "array_utill.h"
#include "stdlib.h"

Array_util create(int type_size, int length){
	Array_util created_array;
	created_array.base = calloc(length,type_size);
	created_array.length = length;
	created_array.type_size = type_size;
	return created_array;
}

Array_util resize(Array_util array, int length){
	int total_size_needed = array.type_size * length;
	array.base = realloc(array.base,total_size_needed);
	array.length = length;
	return array;
}


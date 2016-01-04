#include "array_utill.h"
#include "stdlib.h"

Array_util create(int type_size, int length){
	Array_util created_array;
	created_array.base = calloc(length,type_size);
	created_array.length = length;
	created_array.type_size = type_size;
	return created_array;
}

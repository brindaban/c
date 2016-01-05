#include "array_utill.h"
#include "stdlib.h"
#include "string.h"

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

int areEqual (Array_util firstArray, Array_util secondArray){
	char * first_char_list = (char *)(firstArray.base);
	char * second_char_list = (char *)(secondArray.base); 
	if(firstArray.length != secondArray.length || firstArray.type_size != secondArray.type_size)
		return 0;
	for (int index = 0; index < firstArray.length; index++)
		if(first_char_list[index] != second_char_list[index])
			return 0;
	return 1;
}

void dispose(Array_util array){
	free(array.base);
}

int findIndex(Array_util array, void* element){
	char * list_of_array = (char *)(array.base);
	for (int counter = 0; counter < array.length; counter++){
		if(memcmp(list_of_array,element,array.type_size)==0)
			return counter;
		list_of_array += array.type_size;
	}
	return -1;
}







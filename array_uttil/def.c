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
	if(firstArray.length != secondArray.length || firstArray.type_size != secondArray.type_size
		||memcmp(first_char_list,second_char_list,firstArray.type_size)!=0)
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

Array_util reverse_array(Array_util array){
	int temp;
	int * numbers = (int *)(array.base);
	for (int counter = 0; counter < array.length/2; counter++){
		temp = numbers[counter];
		numbers[counter]=numbers[array.length-1-counter];
		numbers[array.length-1-counter] = temp;
	}
	return array;
}

void* findFirst(Array_util array, MatchFunc* match, void * hint){
	int * numbers = array.base;
	for (int counter = 0; counter < array.length; counter++)
		if(match(hint,&numbers[counter]))
			return &numbers[counter];
	return NULL;
}

void* findLast(Array_util array, MatchFunc* match, void * hint){
	int * numbers = array.base;
	for (int counter = array.length-1; counter >= 0; counter--)
		if(match(hint,&numbers[counter]))
			return &numbers[counter];
	return NULL;
}

int count(Array_util array, MatchFunc* match, void* hint){
	int no_of_elements = 0; 
	int * numbers = array.base;
		for (int counter = 0; counter < array.length; counter++)
			if(match(hint,&numbers[counter]))
				no_of_elements++;
	return no_of_elements;
}
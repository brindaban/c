#include "linkedList.h"
#include "stdlib.h"

void initialize(List *array) {
	array->first =  NULL;
	array->last = NULL;
	array->length = 0;
}

List createList(void){
	List list_of_element;
	initialize(&list_of_element);
	return list_of_element;
}
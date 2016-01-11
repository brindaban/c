#include "linkedList.h"
#include <assert.h>
#include <stdio.h>

void test_for_createList(){
	List list_of_element;
	list_of_element = createList();
	assert(list_of_element.first == NULL);
	assert(list_of_element.last == NULL);
	assert(list_of_element.length == 0);
};

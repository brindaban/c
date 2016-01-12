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

void test_for_add_to_list(){
	List list_of_element;
	int length;
	list_of_element = createList();
	int first = 20;
	length = add_to_list(&list_of_element, &first);
	assert(length==1);
	assert(list_of_element.length==1);
	element * result = (element *)(list_of_element.first);
	assert(*(int *)(result -> value) == 20);
	assert(result -> value == &first);
	assert(result -> next == NULL);
	assert((element *)(list_of_element.last) == result);
	int second = 10;
	length = add_to_list(&list_of_element, &second);
	assert(length == 2);
	assert(list_of_element.length == 2);
	result = (element *)(list_of_element.last);
	assert(*(int *)(result -> value) == 10);


}

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

void test_for_get_first_element(){
	List list_of_element;
	list_of_element = createList();
	int first = 20;
	add_to_list(&list_of_element, &first);
	int second = 10;
	add_to_list(&list_of_element, &second);
	assert(*(int *)(list_of_element.first)->value == 20);
}

void test_for_get_last_element(){
	List list_of_element;
	list_of_element = createList();
	int first = 20;
	add_to_list(&list_of_element, &first);
	int second = 10;
	add_to_list(&list_of_element, &second);
	assert(*(int *)(list_of_element.last)->value == 10);
}

void add_ten_with_each(void * element){
	*(int *)element += 10;
}

void test_for_forEach(){
	List list_of_element;
	list_of_element = createList();
	int first = 20;
	int second = 10;
	int third = 0;

	add_to_list(&list_of_element, &first);
	add_to_list(&list_of_element, &second);
	add_to_list(&list_of_element, &third);

	forEach(list_of_element, &add_ten_with_each);

	assert(*(int *)list_of_element.first->value == 30);
	assert(*(int *)list_of_element.last->value == 10);
}

void test_for_getElementAt(){
	List list_of_element;
	list_of_element = createList();
	int first = 20;
	int second = 10;
	int third = 0;
	
	add_to_list(&list_of_element, &first);
	add_to_list(&list_of_element, &second);
	add_to_list(&list_of_element, &third);

	int * result = (int *)getElementAt(list_of_element,1);
	assert(*result == 10);
	result = (int *)getElementAt(list_of_element,2);
	assert(*result == 0);
}

void test_for_indexOf(){
	List list_of_element;
	list_of_element = createList();
	int first = 20;
	int second = 10;
	int third = 0;
	
	add_to_list(&list_of_element, &first);
	add_to_list(&list_of_element, &second);
	add_to_list(&list_of_element, &third);
	assert(indexOf(list_of_element,&second)==1);
	assert(indexOf(list_of_element,&first)==0);
}

void test_for_deleteElementAt(){
	List list_of_element;
	list_of_element = createList();
	int first = 20;
	int second = 10;
	int third = 0;
	int forth = 12;
	int fifth = 15;

	add_to_list(&list_of_element, &first);
	add_to_list(&list_of_element, &second);
	add_to_list(&list_of_element, &third);
	add_to_list(&list_of_element, &forth);
	add_to_list(&list_of_element, &fifth);


	int * result = (int *)deleteElementAt(&list_of_element,0);
	assert(list_of_element.length==4);
	assert(list_of_element.first->value==&second);
	assert(list_of_element.last->value==&fifth);

}

void test_for_asArray(){
	List list_of_element;
	list_of_element = createList();
	int first = 20;
	int second = 10;
	int third = 0;
	int forth = 12;
	int fifth = 15;

	add_to_list(&list_of_element, &first);
	add_to_list(&list_of_element, &second);
	add_to_list(&list_of_element, &third);
	add_to_list(&list_of_element, &forth);
	add_to_list(&list_of_element, &fifth);

	int *array[8], maxElements = 8;
	void ** array_pointer = (void **)array;

	int result = asArray(list_of_element,array_pointer,maxElements);
	assert(result == 5);
	assert(*array[0]==20);
	assert(*array[1]==10);
	assert(*array[2]==0);
	assert(*array[3]==12);
	assert(*array[4]==15);
}

int isEven(void* hint, void* item){
	int * number = (int *)(item);
	return !(*number % 2);
}

void test_for_filter(){
	List list_of_element;
	list_of_element = createList();
	int first = 21;
	int second = 10;
	int third = 0;
	int forth = 12;
	int fifth = 15;

	add_to_list(&list_of_element, &first);
	add_to_list(&list_of_element, &second);
	add_to_list(&list_of_element, &third);
	add_to_list(&list_of_element, &forth);
	add_to_list(&list_of_element, &fifth);
	void * even_hint = NULL;
	List filtered_list_of_element = filter(list_of_element,&isEven,even_hint);
	assert(filtered_list_of_element.length==3);
	assert(*(int *)((element *)(filtered_list_of_element.first)->value) == 10);
	assert(*(int *)((element *)(filtered_list_of_element.last)->value) == 12);
}

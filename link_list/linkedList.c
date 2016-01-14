#include "linkedList.h"
#include "stdlib.h"
#include "stdio.h"

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

int add_to_list(List * list_of_element,void * element_to_push){
	element *node;
	node = (element *)malloc(sizeof(element));
	node->value = element_to_push;
	node->next = NULL;
	if(list_of_element->length==0){
		list_of_element->first = list_of_element->last =  node;
	}
	else{
		list_of_element->last->next = node;
		list_of_element->last = node;
	}
	list_of_element->length++;
	return list_of_element->length;
}

void * get_first_element(List list_of_element){
	return (element *)(list_of_element.first)->value;
}

void *get_last_element(List list_of_element){
	return (element *)(list_of_element.last)->value;
}

void forEach(List list_of_element, ElementProcessor change_function){
	element * node = (element *)(list_of_element.first);
	while(node != NULL){
		change_function(node->value);
		node=node->next;
	}
}
void * getElementAt(List list_of_element, int position){
	int counter = 0;
	element * node = (element *)(list_of_element.first);
	while(counter<position){
		node = node->next;
		counter++;
	}
	return node->value;
}

int indexOf(List list_of_element, void * value_pointer){
	int counter = 0;
	element * node = (element *)(list_of_element.first);
	while(node != NULL){
		if(node->value==value_pointer)
			return counter;
		node = node->next;
		counter++;
	}
	return -1;
}

void * deleteElementAt(List *list_of_element, int position){
	int counter = 0;
	element * node = (element *)(list_of_element->first);
	if(position >= list_of_element->length) return NULL;
	if(position==0){
		list_of_element->first = node->next;
		list_of_element->length--;
		return node->value;
	}
	while(counter < position-1){
		node = node ->next;
		counter++;
	}

	element * current = node->next;
	node->next = current->next;
	list_of_element->length--;
	return current->value;
}

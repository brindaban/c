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

int asArray(List list_of_element, void ** array_pointer, int maxElements){
	int counter = 0,length;
	element *node = list_of_element.first;
	length = list_of_element.length < maxElements ? list_of_element.length : maxElements;
	for(counter = 0; counter < length; counter++){
		*array_pointer = node->value;
		array_pointer++;
		node = node->next;
	}
	return length;
}

List  filter(List list_of_element, MatchFunc check_function, void * hint){
	List filtered_list_of_element = createList();
	element * node = list_of_element.first;
	while(node!=NULL){
		if(check_function(hint,node->value))
			add_to_list(&filtered_list_of_element,node->value);
		node = node->next;
	}
	return filtered_list_of_element;
}

List reverse(List list_of_element){
	void **array = calloc(list_of_element.length,8);
	asArray(list_of_element,array,list_of_element.length);
	List reversed_list_of_element = createList();
	for(int i=list_of_element.length-1; i>=0; i--) 
		add_to_list(&reversed_list_of_element, (void *)array[i]);
	return reversed_list_of_element;
}

List map(List list_of_element, ConvertFunc change_function, void * hint ){
	List convert_list_of_element = createList();
	element * node = list_of_element.first;
	void * destinationItem;
	while(node != NULL){
		destinationItem = malloc(sizeof(void *));
		change_function(hint, node->value, destinationItem);
		add_to_list(&convert_list_of_element,destinationItem);
		node = node->next;
	}
	return convert_list_of_element;
}

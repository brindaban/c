#include "list.h"
void initialize(List *array) {
array->first = array->last = NULL;
array->length = 0;
}
void enqueue(List *array,int value){
element *e;
e = (element *)malloc(sizeof(element));
e->value = value;
e->next = NULL;
if(array->length==0){
array->first = array->last =  e;
}
else{
array->last->next = e;
array->last = e;
}
array->length++;
printf("pushed %d\n", array->length);
}
void print_list(List array){
int counter = 0;
while(counter<array.length){
printf("%d\n",array.first->value);
array.first = array.first->next;
counter++;
}
}
int dequeue(List *array){
int result;
element * e;
e =  array->first;
result = e->value;
array->first = e->next;
free(e);
array->length--;
return result;
}
void insert_in_position(List *array, int value, int position){
int count = 1;
element *e;
e = (element *)malloc(sizeof(element));
e->value = value;
element *input;
input = array->first;
while(count<position-1){
input = input->next;
count++;
}
e->next = input->next;
input->next = e;
array->length++;
}

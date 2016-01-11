#include <stdio.h>
typedef struct element{
int value;
struct element * next;
} element;
typedef struct list {
element * first;
element * last;
int length;
} List;

void initialize(List *array);
void enqueue(List *array,int value);
void print_list(List array);
int dequeue(List *array);
void insert_in_position(List *array, int value, int position);
#include <stdio.h>
#include "list.h"
int main(void) {
List list_of_element;
initialize(&list_of_element);
enqueue(&list_of_element,12);
enqueue(&list_of_element,34);
enqueue(&list_of_element,11);

print_list(list_of_element);

// printf("%d\n",list_of_element.length );
printf("%d\n",dequeue(&list_of_element));
printf("%d\n",dequeue(&list_of_element));
printf("%d\n",dequeue(&list_of_element));
// push(&list_of_element,100);
// printf("%d\n",list_of_element.length );
// print_list(list_of_element);
// printf("-----------------------\n" );
// insert_in_position(&list_of_element,99,2);
// insert_in_position(&list_of_element,199,3);
// print_list(list_of_element);

return 0;
}
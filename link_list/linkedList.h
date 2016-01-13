typedef void (*ElementProcessor)(void *);


typedef struct element{
	void * value;
	void * next;
} element;

typedef struct list {
	element * first;
	element * last;
	int length;
} List;

List createList(void);
int add_to_list(List *, void *);
void *get_first_element(List);
void *get_last_element(List);
void forEach(List, ElementProcessor );
void * getElementAt(List, int );
int indexOf(List, void *);

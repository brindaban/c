typedef void (*ElementProcessor)(void *);

typedef int (*MatchFunc)(void* , void*);

typedef void (*ConvertFunc)(void* hint, void* sourceItem, void* destinationItem);

typedef void * (*Reducer)(void* hint, void* previousItem, void* item);


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
void * deleteElementAt(List *, int);
List  filter(List, MatchFunc, void * );
int asArray(List, void **, int );
List reverse(List);
List map(List, ConvertFunc, void * );
void * reduce(List, Reducer, void *hint, void *initialValue);




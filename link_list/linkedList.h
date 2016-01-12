typedef struct element{
	void * value;
	struct element * next;
} element;

typedef struct list {
	element * first;
	element * last;
	int length;
} List;

List createList(void);
int add_to_list(List *, void *);
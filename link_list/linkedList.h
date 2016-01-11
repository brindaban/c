typedef struct element{
	int value;
	struct element * next;
} element;

typedef struct list {
	element * first;
	element * last;
	int length;
} List;

List createList(void);
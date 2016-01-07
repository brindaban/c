typedef int (MatchFunc)(void *, void *);

typedef void (ConvertFunc)(void *, void *, void *);

typedef void (OperationFunc)(void *, void *);

typedef void * (ReducerFunc)(void *, void *,void *);

typedef struct array_util
{
	void * base;
	int length;
	int type_size;
} Array_util;

Array_util create(int type_size, int length);
Array_util resize(Array_util array, int length);
Array_util reverse_array(Array_util array);
int areEqual (Array_util firstArray, Array_util secondArray);
void dispose(Array_util array);
int findIndex(Array_util array, void* element);
void* findFirst(Array_util array, MatchFunc * match, void * hint);
void* findLast(Array_util array, MatchFunc * match, void * hint);
int count(Array_util array, MatchFunc* match, void* hint);
int filter(Array_util array, MatchFunc* match, void* hint, void** destination, int maxItems );
void map(Array_util source, Array_util destination, ConvertFunc* convert, void* hint);
void forEach(Array_util array, OperationFunc* operation, void* hint);
void* reduce(Array_util array, ReducerFunc* reducer, void* hint, void* intialValue);
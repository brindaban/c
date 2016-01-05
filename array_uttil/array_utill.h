typedef struct array_util
{
	void * base;
	int length;
	int type_size;
} Array_util;

Array_util create(int type_size, int length);
Array_util resize(Array_util array, int length);
int areEqual (Array_util firstArray, Array_util secondArray);
void dispose(Array_util array);
int findIndex(Array_util array, void* element);
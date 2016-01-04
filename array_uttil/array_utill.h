typedef struct array_util
{
	void * base;
	int length;
	int type_size;
} Array_util;

Array_util create(int type_size, int length);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>


/*

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]


*/



/*
push = 1
pop = 0

wrong: 100011
right: 100110


*/

char * str;
char ** beginPtr;
int limit;

int size;

void myGene(int num, int len, int index);

char** generateParenthesis2(int n, int* returnSize) {
	int num = 0;
	size = 0;
	beginPtr = NULL;

	str = malloc(sizeof(char) * 2 * n + 1);
	str[2 * n] = 0;
	limit = n;

	myGene(num, 2 * n, 0);
	*returnSize = size;

	return beginPtr;
}

void myGene(int num, int len, int index)
{
	// printf( "%s %d\n", str, num );

	if (len == 0)
	{
		if (num != 0)
		{
			// printf( "no : str %s  num %d\n", str, num );
			return;
		}


		// printf( "yes : str %s\n", str );
		beginPtr = realloc(beginPtr, sizeof(char *) * (++size));
		beginPtr[size - 1] = malloc(sizeof(char) * 2 * limit + 1);
		strcpy(beginPtr[size - 1], str);
	}
	else
	{
		str[index] = '(';
		myGene(num + 1, len - 1, index + 1);

		if (num > 0)
		{
			str[index] = ')';
			myGene(num - 1, len - 1, index + 1);
		}
	}
}


void process(char* store_array, int idx, char** ret, int length, int* returnSize, int push_count, int cur_idx)
{
	if (idx == length)
	{
		char* new_str = malloc((length + 1) * sizeof(char));
		memcpy(new_str, store_array, length * sizeof(char));
		new_str[length] = 0;
		ret[*returnSize] = new_str;
		*returnSize += 1;
		return;

	}
	for (int i = 40; i < 42; i++)
	{
		bool push_success = false;
		if (i == 40)
		{
			if (push_count < length / 2 && cur_idx < length / 2)
			{
				store_array[idx] = '(';
				push_success = true;
			}
			else {
				continue;
			}
		}
		else {
			if (cur_idx > 0)
			{
				store_array[idx] = ')';
			}
			else {
				continue;
			}
		}
		if (push_success)
			process(store_array, idx + 1, ret, length, returnSize, push_count + 1, cur_idx + 1);
		else
			process(store_array, idx + 1, ret, length, returnSize, push_count, cur_idx - 1);
	}
}



char** generateParenthesis(int n, int* returnSize) {
	*returnSize = 0;
	if (n == 0)
		return NULL;
	int length = n * 2;
	char** ret = malloc(20000 * sizeof(char*));
	char* store_array = malloc(length * sizeof(char));
	int push_count = 0;
	int cur_top = 0;
	process(store_array, 0, ret, length, returnSize, push_count, cur_top);
	free(store_array);
	return ret;


}

int main()
{
	int returnSize = 0;
	int n = 2;
	char** ret = generateParenthesis2(2, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%s\n", ret[i]);
	}

	getchar();

	return 0;
}
